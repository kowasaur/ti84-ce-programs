#include <tice.h>
#include <stdio.h>
#include <stdbool.h>

#define HEIGHT 10
#define WIDTH 26
#define TILES 234 // 9 * 26
#define DEFAULT_Y 5
#define DEFAULT_X 13

typedef unsigned int uint;

// TODO: https://www.reddit.com/r/Minesweeper/comments/m2x9d6/rules_for_mine_spawning/gqmb02l

/* Controls
Help - 3
Flag - 1
Destroy - 2
Quit - 0
*/

// It's probably bad that all of these are global but whatever
sk_key_t key;
char rendered_char[HEIGHT][WIDTH];
bool is_mine[HEIGHT][WIDTH];
uint curY = DEFAULT_Y, curX = DEFAULT_X; // Default cursor position
uint8_t num_mines = 0, num_destroyed = 0;

// So that it's never negative
uint safeSub(uint base, uint sub) {
  return sub >= base ? 0 : base - sub;
}

// Add up to a maximum value
uint safeAdd(uint base, uint add, uint max) {
  uint result = base + add;
  return result > max ? max : result;
}

// Check if numbers are close to equal
bool isClose(uint8_t n, uint comp) {
  return n >= safeSub(comp, randInt(1, 3)) && n <= comp + randInt(1, 3);
}

void renderText(char str[WIDTH], uint8_t y, uint8_t x) {
  os_SetCursorPos(y, x);
  os_PutStrLine(str);
  // Put cursor back to where it was
  os_SetCursorPos(curY, curX);
}

void renderChar(char c, uint8_t y, uint8_t x) {
  char str[] = {c, '\0'};
  renderText(str, y, x);
  rendered_char[y][x] = c;
}

void changeCursor(int8_t change_y, int8_t change_x) {
  // ! Don't use global variable here since it changes it
  uint y, x;
  os_GetCursorPos(&y, &x);
  renderChar(rendered_char[y][x], y, x); // cleanup
  y += change_y;
  x += change_x;
  if (!(y == 0 || y == HEIGHT || x >= WIDTH)) {
    os_SetCursorPos(y, x);
    curY = y;
    curX = x;
  }
}

bool help() {
  os_DisableCursor();
  os_ClrHome();
  
  renderText("Minesweeper Controls", 0, 0);
  renderText("0 - Quit", 2, 0);
  renderText("1 - Flag", 3, 0);
  renderText("2 - Destroy", 4, 0);
  renderText("3 - Num/Flag Destroy", 5, 0);
  renderText("4 - Help", 6, 0);
  renderText("Press anything", 8, 0);
  renderText("to continue", 9, 0);

  while (!(key = os_GetCSC()));
  if (key == sk_0) return false;

  // Render game
  renderText("Press 4 for help       ", 0, 0);
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      renderChar(rendered_char[i][j], i, j);
    }
  }

  os_SetCursorPos(curY, curX);
  os_EnableCursor();
  return true;
}

// Allow to move, quit and help before destroying anything
bool startedGame() {
  while (true) {
    while (!(key = os_GetCSC())); // wait for key
    switch (key) {
      case sk_Left:
        changeCursor(0, -1);
        break;
      case sk_Right:
        changeCursor(0, 1);
        break;
      case sk_Up:
        changeCursor(-1, 0);
        break;
      case sk_Down:
        changeCursor(1, 0);
        break;
      case sk_0:
        return false;
      case sk_2:
        return true;
      case sk_4:
        if (!help()) return false;
        break;
      default:
        break;
    }
  }
}

void endGame(char msg[WIDTH - 8]) {
  os_DisableCursor();
  os_ClrHome();
  renderText(msg, 5, 8);
  while (!os_GetCSC());
}

bool destroy(uint y, uint x) {
  if (rendered_char[y][x] != ' ') return true;
  
  if (is_mine[y][x]) {
    endGame("You died");
    return false;
  }
  uint8_t surrounding_mines = 0;
  for (uint8_t row = safeSub(y, 1); row <= safeAdd(y, 1, HEIGHT - 1); row++) {
    for (uint8_t col = safeSub(x, 1); col <= safeAdd(x, 1, WIDTH - 1); col++) {
      if (is_mine[row][col]) surrounding_mines++;
    }
  }
  // + '0' converts to digit char
  renderChar(surrounding_mines + '0', y, x);
  if (surrounding_mines == 0) {
    for (uint8_t row = safeSub(y, 1); row <= safeAdd(y, 1, HEIGHT - 1); row++) {
      for (uint8_t col = safeSub(x, 1); col <= safeAdd(x, 1, WIDTH - 1); col++) {
        if (!is_mine[row][col]) destroy(row, col);
      }
    }
  }
  
  num_destroyed++;
  if (num_destroyed == TILES - num_mines) {
    endGame("You won!");
    return false;
  }
  
  return true;
}

int main() {
  srandom(rtc_Time());
  os_ClrHome();
  os_EnableCursor(); // Visible cursor

  renderText("Press 4 for help", 0, 0);
  // Render spaces so that cursor cleanup works
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      renderChar(' ', i, j);
    }
  }
  os_SetCursorPos(DEFAULT_Y, DEFAULT_X);

  if (!startedGame()) return 0;

  // Generate mines
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      if (isClose(i, curY) && isClose(j, curX)) is_mine[i][j] = false;
      else is_mine[i][j] = randInt(1, 10) <= 3;
      if (is_mine[i][j]) num_mines++;
    }
  }
  destroy(curY, curX);
  // Render mines (for debugging)
  // for (uint8_t i = 1; i < HEIGHT; i++) {
  //   for (uint8_t j = 0; j < WIDTH; j++) {
  //     bool m = is_mine[i][j];
  //     if (m) renderChar('M', i, j);
  //     else renderChar(' ', i, j);
  //   }
  // }
  
  while (true) {
    while (!(key = os_GetCSC())); // wait for key
    switch (key) {
      case sk_Left:
        changeCursor(0, -1);
        break;
      case sk_Right:
        changeCursor(0, 1);
        break;
      case sk_Up:
        changeCursor(-1, 0);
        break;
      case sk_Down:
        changeCursor(1, 0);
        break;
      case sk_0:
        return 0;
      case sk_1: // flagging
        if (rendered_char[curY][curX] == ' ') renderChar('F', curY, curX);
        else if (rendered_char[curY][curX] == 'F') renderChar(' ', curY, curX);
        break;
      case sk_2:
        if(!destroy(curY, curX)) return 0;
        break;
      case sk_4:
        if (!help()) return 0;
        break;
      default:
        break;
    }
  }
}
