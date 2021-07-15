#include <tice.h>
#include <stdio.h>
#include <stdbool.h>

#define HEIGHT 10
#define WIDTH 26
#define DEFAULT_Y 5
#define DEFAULT_X 13

// This might be right idk. I did it cause vscode was giving a squiggly
typedef unsigned int uint24_t;

/* Controls
Help - 3
Flag - 1
Destroy - 2
Quit - 0
*/

sk_key_t key;
char rendered_char[HEIGHT][WIDTH];

void renderText(char c[WIDTH], uint8_t y, uint8_t x) {
  uint24_t cY, cX; // user cursor position
  os_GetCursorPos(&cY, &cX);
  os_SetCursorPos(y, x);
  os_PutStrLine(c);
  // Put cursor back to where it was
  os_SetCursorPos(cY, cX);
}

void renderChar(char c, uint8_t y, uint8_t x) {
  char str[] = {c, '\0'};
  renderText(str, y, x);
  rendered_char[y][x] = c;
}

void changeCursor(int8_t change_y, int8_t change_x) {
  uint24_t y, x;
  os_GetCursorPos(&y, &x);
  renderChar(rendered_char[y][x], y, x); // cleanup
  y += change_y;
  x += change_x;
  if (!(y == 0 || y == HEIGHT || x >= WIDTH)) {
    os_SetCursorPos(y, x);
  }
}

bool displayHelp() {
  os_ClrHome();
  os_DisableCursor();
  
  renderText("Minesweeper Controls", 0, 0);
  renderText("0 - Quit", 2, 0);
  renderText("1 - Flag", 3, 0);
  renderText("2 - Destroy", 4, 0);
  renderText("3 - Help", 5, 0);
  renderText("Press anything", 8, 0);
  renderText("to continue", 9, 0);

  while (!(key = os_GetCSC()));
  if (key == sk_0) return false;

  // Render game
  renderText("Press 3 for help       ", 0, 0);
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      renderChar(rendered_char[i][j], i, j);
    }
  }

  os_SetCursorPos(DEFAULT_Y, DEFAULT_X);
  os_EnableCursor();
  return true;
}

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
      case sk_3:
        if (!displayHelp()) return false;
        break;
      default:
        break;
    }
  }
}

int main() {
  srandom(rtc_Time());
  os_ClrHome();
  os_EnableCursor(); // Visible cursor

  uint24_t y = DEFAULT_Y, x = DEFAULT_X; // Default cursor position
  bool is_mine[HEIGHT][WIDTH];

  renderText("Press 3 for help", 0, 0);
  // Render spaces so that cursor cleanup works
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      renderChar(' ', i, j);
    }
  }
  os_SetCursorPos(y, x);

  if (!startedGame()) return 0;
  os_GetCursorPos(&y, &x);
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      if (i == y && j == x) is_mine[i][j] = false;
      else is_mine[i][j] = randInt(1, 5) == 1;
    }
  }
  for (uint8_t i = 1; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      bool m = is_mine[i][j];
      if (m) renderChar('1', i, j);
      else renderChar('0', i, j);
    }
  }
  
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
      case sk_2:
        break;
      case sk_3:
        if (!displayHelp()) return 0;
        break;
      default:
        break;
    }
  }
}
