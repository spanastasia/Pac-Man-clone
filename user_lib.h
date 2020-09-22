#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "types.h"
#define LEN 31
#define WID 28

#ifndef user_lib
#define user_lib

void Draw(Square maze[LEN][WID]);
void Setup(int arr[LEN][WID], Square maze[LEN][WID], int* gameover);
void Input(Square* pacman, Square maze[LEN][WID], int* gameover, int* score);
void moveGhost(Square* ghost, int desX, int desY);
int leaveHome(Square* ghost);
void intilizeWaveMatrix(int arr[LEN][WID], int grid[LEN][WID]);
int lee(int ax, int ay, int bx, int by, int grid[LEN][WID], int px[LEN*WID], int py[LEN*WID]);
void drawSquare(int num, int prevX[4], int prevY[4], Square* square, Square maze[LEN][WID]);
#endif
