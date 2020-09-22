#include "user_lib.h"

//Initilize an array of structures Square
void Setup(int arr[LEN][WID], Square maze[LEN][WID], int* gameover) {
	int i, j;
	for (i = 0; i < LEN; i++) {
		for (j = 0; j < WID; j++) {
			if (arr[i][j] == 1) {
				maze[i][j].type = WALL;
			} else maze[i][j].type = TUNNEL;
		}
		if ((i > 12 && i < 16 && j > 10 && j < 17) || (i == 12 && j == 13 ||  i == 12 && j == 14)) {
			maze[i][j].visited = 1;
		} else {
			maze[i][j].visited = 0;
		}
		maze[i][j].x = j;
		maze[i][j].y = i;
	}
	*gameover = 0;
}

