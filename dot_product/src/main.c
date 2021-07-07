#include <tice.h>
// #include <stdio.h>
#include <stdlib.h>
// #include <math.h>

// * This was orginally mean to calculate the scalar resolute but
// * Finding the unit vector didn't work

typedef struct Vector {
    float i;
    float j;
} Vector;

// float magnitude(Vector v) {
//     return sqrtf(v.i * v.i + v.j * v.j);
// }

// Vector unitVector(Vector v) {
//     float mag = magnitude(v);
//     Vector u = {v.i / mag, v.j / mag};
//     return u;
// }

float dotProduct(Vector v1, Vector v2) {
    return v1.i * v2.i + v1.j * v2.j;
}

// float scalarResolute(Vector v1, Vector v2) {
//     return dotProduct(v1, unitVector(v2));
// }

void wait(){
    while (!os_GetCSC());
}

void newLineOut(char msg[], uint8_t *line) {
    os_SetCursorPos(*line, 0);
    (*line)++;
    os_PutStrLine(msg);
}

float numInput(char msg[], uint8_t *line) {
    char inputBuffer[10];
    char *ignore; // only exists to satisfy funtion
    os_SetCursorPos(*line, 0);
    (*line)++;
    os_GetStringInput(msg, inputBuffer, 10);
    return strtof(inputBuffer, &ignore);
}

int main(void) {
    char resultString[25];
    uint8_t cLine = 0;

    os_ClrHome();

    newLineOut("This program calculates", &cLine);
    newLineOut("the dot product", &cLine);
    // newLineOut("the scalar projection", &cLine);
    newLineOut("of two vectors", &cLine);
    cLine = 9;
    newLineOut("Press any key", &cLine);
    wait();

    os_ClrHome();

    cLine = 0;
    newLineOut("Vector A", &cLine);
    Vector a = {numInput("i: ", &cLine), numInput("j: ", &cLine)};

    cLine = 4;
    newLineOut("Vector B", &cLine);
    Vector b = {numInput("i: ", &cLine), numInput("j: ", &cLine)};

    // float result = scalarResolute(a, b);
    float result = dotProduct(a, b);

    os_SetCursorPos(9, 0);
    real_t rResult = os_FloatToReal(result);
    os_RealToStr(resultString, &rResult, 0, 0, -1);
    os_PutStrLine(resultString);

    wait();

    /* Return 0 for success */
    return 0;
}
