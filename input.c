#include "user_lib.h"

//Catchs key presses and changes position of pacman
void Input(Square* pacman, Square maze[LEN][WID], int* gameover, int* score) {
	int x, y, c;
	x = pacman->x;
	y = pacman->y;
	if(!maze[y][x].visited) {
		maze[y][x].visited = 1;
		(*score)++;
	}
	if (kbhit()) {
		if (GetAsyncKeyState(VK_LEFT)) {
			if (maze[y][x-1].type != WALL)
				pacman->x--;
			else if (y == 14 && x == 0)
				pacman->x = WID - 1;
		}
				
		else if (GetAsyncKeyState(VK_RIGHT)) {
			if (maze[y][x+1].type != WALL)
			pacman->x++;
			else if (y == 14 && x == WID - 1)
			pacman->x = 0;
		}
		else if (GetAsyncKeyState(VK_UP)) {
			if (maze[y-1][x].type != WALL)
			pacman->y--;
		}
		else if (GetAsyncKeyState(VK_DOWN)) {
			if (maze[y+1][x].type != WALL) {
				pacman->y++;
				if (y == 11 && (x == 13 || x == 14))
					pacman->y--;
			}
		}
		else if (c = getch() == 27) {
			while(1) {
				c = getch();
				if (c == 13) break;
				if (c == 27) {
					*gameover = 1;
					break;
				}
			}
		}
	}
	
}
