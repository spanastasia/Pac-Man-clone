#include "user_lib.h"


//Gets an array of structures Square and draws a labirynth
void Draw(Square maze[LEN][WID]) {
	system("cls");
	int i, j;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < WID; j++) {
			if (i == 12 && (j == 13 || j == 14)) {
				printf("%c%c%c", 196, 196, 196);
				continue;
			}
			if ((i > 12 && i < 16) && (j > 10 && j < 17)) {
				printf("   ");
				continue;
			}
			if(maze[i][j].type == WALL) {
				printf("%c%c%c", 219, 219, 219);
			} else if (maze[i][j].type == TUNNEL && !maze[i][j].visited) {
				printf(" %c ", 249);
			}
				
		}
		printf("\n");
	}
}

//Gets number of character (0 - pacman, 1 - 3 is fo ghosts), arrays with previous position of character, pointer to this character and array of Squares. Draws characters in theirs new positions
void drawSquare(int num, int prevX[4], int prevY[4], Square* square, Square maze[LEN][WID]) {
	COORD point;
  	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
  	point.X = 3*prevX[num]; point.Y = prevY[num];
  	SetConsoleCursorPosition(hout, point);
  	if (maze[prevY[num]][prevX[num]].visited || (prevY[num] > 12 && prevY[num] < 16 && prevX[num] > 10 && prevX[num] < 17)) printf("   ");
  	else if (prevY[num] == 12 && (prevX[num] == 13 || prevX[num] == 14)) printf("%c%c%c", 196, 196, 196);
  	else printf(" %c ", 249);
  	point.X = 3*square->x; point.Y = square->y;
  	SetConsoleCursorPosition(hout, point);
  	if (num == 0) printf("%c_%c", 253, 253);
  	else if (num == 1) printf("o_O");
  	else if (num == 2) printf("o_O");
  	else if (num == 3) printf("o_O");
  	prevX[num] = square->x;
  	prevY[num] = square->y;
  	point.X = 0; point.Y = 31;
  	SetConsoleCursorPosition(hout, point);
}

