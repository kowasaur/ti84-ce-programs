#include <tice.h>
#include <stdio.h>

int main() {
  uint8_t score = 0;
  uint8_t key;
  char str[4];

  os_ClrHome();

  os_SetCursorPos(8, 0);
  os_PutStrLine("Click any key");
  os_SetCursorPos(9, 0);
  os_PutStrLine("Press 0 to quit");

  while (1) {
    sprintf(str, "%d", score++);
    os_SetCursorPos(0, 1);
    os_PutStrLine(str);

    // Wait for key and end program if 0
    while (!(key = os_GetCSC()));
    if (key == sk_0) {
      return 0;
    }
  }
}
