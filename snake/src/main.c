#include <tice.h>
#include <stdio.h>

// * All co-ordinates in this file will be (y, x)

#define HEIGHT 9
#define WIDTH 25
#define TILES 200 // WIDTH * HEIGHT

uint8_t const validKeys[] = {sk_Right, sk_Left, sk_Up, sk_Down};

int validKey(uint8_t key) {
  for (uint8_t i = 0; i < 4; i++) {
    if (key == validKeys[i]) return 1;
  }
  return 0;
}

void renderChar(char c[1], uint8_t coords[2]) {
  os_SetCursorPos(coords[0], coords[1]);
  os_PutStrLine(c);
}

void newApple(uint8_t apple[], uint8_t length, uint8_t snake[TILES][2]) {
  uint8_t a_y, a_x, invalid_a = 1;
  while (invalid_a) {
    for (uint8_t i = 0; i < length; i++) {
      a_y = randInt(1, HEIGHT);
      a_x = randInt(0, WIDTH);
      if (a_y == snake[i][0] && a_x == snake[i][1]) {
        invalid_a = 1;
        break;
      }
      invalid_a = 0;
    }
  }
  renderChar("#", apple);
  apple[0] = a_y;
  apple[1] = a_x;
  renderChar("@", apple);
}

int main() {
  srandom(rtc_Time());

  uint8_t score = 0;
  uint8_t key = sk_Right;
  uint8_t new_key, y, x;
  char str[23];

  uint8_t length = 3; // length of snake 
  uint8_t snake[TILES][2] = {{5, 9}, {5, 8}, {5, 7}};
  uint8_t apple[] = {5, 16};

  // Clear screen
  os_ClrHome();

  renderChar("@", apple);
  renderChar("#", snake[0]);
  renderChar("#", snake[1]);
  renderChar("#", snake[2]);

  while (1) {
    sprintf(str, "Score: %d | 0 to quit", score);
    os_SetCursorPos(0, 0);
    os_PutStrLine(str);

    for (uint8_t i = 0; i < 40; i++) {
      new_key = os_GetCSC();
      if (new_key) break;
    }
    delay(150);

    if (new_key == sk_0) return 0;
    // So you can't kill yourself by doing a 180
    if (!((new_key == sk_Left && key == sk_Right) || (new_key == sk_Right && key == sk_Left) 
      || (new_key == sk_Up && key == sk_Down) || (new_key == sk_Down && key == sk_Up)
    ) && validKey(new_key)) key = new_key;
    
    y = snake[0][0];
    x = snake[0][1];
    if (key == sk_Right) x++;
    else if (key == sk_Left) x--;
    else if (key == sk_Up) y--;
    else y++; // Down
    for (uint8_t i = length; i > 0; i--) {
      snake[i][0] = snake[i - 1][0];
      snake[i][1] = snake[i - 1][1];
      // Collide with self
      if (y == snake[i][0] && x == snake[i][1]) goto END; // probably bad but whatever
      // This exists since sometimes the check earlier fails. Idk why
      if (apple[0] == snake[i][0] && apple[1] == snake[i][1]) newApple(apple, length, snake);
      
    }
    length++;
    snake[0][0] = y;
    snake[0][1] = x;
    
    // Check if wall collision
    if (y == 0 || y == HEIGHT + 1 || x >= WIDTH + 1 ) {
      break;
    }

    renderChar("#", snake[0]);

    // Eat apple
    if (apple[0] == y && apple[1] == x) {
      score++;
      newApple(apple, length, snake);
    } else {
      length--;
      renderChar(" ", snake[length]);
    }
  }

  END:;

  uint8_t showDied = 0;
  uint8_t counter = 1;

  while (1) {
    key = os_GetCSC();
    if (key == sk_0) return 0;
    if (key == sk_1) main();

    os_SetCursorPos(0, 0);

    if (showDied % 3 == 2) {
      sprintf(str, "Score: %d | 0 to quit", score);
    } else if (showDied % 3 == 1) {
      sprintf(str, "Score: %d | 1 to play", score);
    }else {
      sprintf(str, "Score: %d | You died ", score);
    }
    os_PutStrLine(str);
    if (counter % 241 == 0) showDied++; 
    counter++;
  }
}
