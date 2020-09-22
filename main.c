#include "user_lib.h"
char title[] = "Shmac-Man";


int arr[LEN][WID] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1}, 
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1}, 
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,2,2,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,3,3,3,3,3,3,1,0,1,1,0,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0,1,3,3,3,3,3,3,1,0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,0,1,1,0,1,3,3,3,3,3,3,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,0,1,1,1,1,1,0,1,1,1,1,0,1},
		{1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
		{1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1},
		{1,1,1,0,1,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1},
		{1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
int grid[LEN][WID];
int px[LEN * WID], py[LEN * WID];

Square maze[LEN][WID];
int gameover, score = 0;
Square pacman = {PACMAN, 0, 15, 29};

Square ghost1 = {GHOST, 0, 13, 14};
Square ghost2 = {GHOST, 0, 14, 14};
Square ghost3 = {GHOST, 0, 15, 14};
int lives[3] = {1, 1, 1};
int prevX[4] = {15, 13, 14, 15};
int prevY[4] = {29, 14, 14, 14};

int main() {
	//Window configuration
	SetConsoleTitle(title);
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hout,&structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hout, &structCursorInfo );
	system("mode con cols=84 lines=36");
	
	
	
	int i, j, counter = 0;
	//Drawing fiela
	Setup(arr, maze, &gameover);
	Draw(maze);
	
	//Main game cicle
	while(!gameover) {
		Input(&pacman, maze, &gameover, &score); //Catches button press and install pacman position
		
		if (!(counter%3) && counter > 30) { //First ghost starts moving after aprox. 3 seconds after begining and moves with velocity three times less than pacman does
			int boolean = leaveHome(&ghost1);
			if (boolean) {
				intilizeWaveMatrix(arr, grid);
				if (counter%900 < 600) {
				lee(ghost1.x, ghost1.y, pacman.x, pacman.y, grid, px, py);
				} else if (ghost1.x != 13 && ghost1.y != 17) lee(ghost1.x, ghost1.y, 13, 17, grid, px, py);
				else lee(ghost1.x, ghost1.y, 14, 11, grid, px, py);
				ghost1.x = px[1];
				ghost1.y = py[1];
			}
		}
		if (!(counter%5) && counter > 90) { //Second ghost starts after 9 seconds and moves in 5 times more slowly than pacman does
			int boolean = leaveHome(&ghost2);
			if (boolean) {
				intilizeWaveMatrix(arr, grid);
				if (counter%1000 < 500) {
					lee(ghost2.x, ghost2.y, pacman.x, pacman.y, grid, px, py);
				} else if (ghost2.x != 1 && ghost2.y != 1) lee(ghost2.x, ghost2.y, 1, 1, grid, px, py);
				else lee(ghost2.x, ghost2.y, 26, 29, grid, px, py);
				
				ghost2.x = px[1];
				ghost2.y = py[1];
			}
		}
		if (!((counter*10)%25) && counter > 150) { //Third ghost starts after 15 seconds and moves in 2.5 times more slowly than pacman does
			int boolean = leaveHome(&ghost3);
			if (boolean) {
				intilizeWaveMatrix(arr, grid);
				if (counter%1200 < 750) {
					lee(ghost3.x, ghost3.y, pacman.x, pacman.y, grid, px, py);
				} else if (ghost3.x != 26 && ghost3.y != 1) lee(ghost3.x, ghost3.y, 26, 1, grid, px, py);
				else lee(ghost2.x, ghost2.y, 1, 29, grid, px, py);
				ghost3.x = px[1];
				ghost3.y = py[1];
			}
		}
		//Drawing ghosts and pacman in new positions
		drawSquare(0, prevX, prevY, &pacman, maze); 
		drawSquare(1, prevX, prevY, &ghost1, maze);
		drawSquare(2, prevX, prevY, &ghost2, maze);
		drawSquare(3, prevX, prevY, &ghost3, maze);
		counter++;
		
		//Information bar
		if ((ghost1.x == pacman.x && ghost1.y == pacman.y) || (ghost2.x == pacman.x && ghost2.y == pacman.y) || (ghost2.x == pacman.x && ghost2.y == pacman.y)) {
			int num = 0;
			for (i = 0; i < 3; i++) {
				if (lives[i]) num++;
			}
			if (num) {
				lives[num - 1] = 0;	
				pacman.x = 15;
				pacman.y = 29;
				ghost1.x = 13;
				ghost1.y = 14;
				ghost2.x = 14;
				ghost2.y = 14;
				ghost3.x = 15;
				ghost3.y = 14;
				counter = 0;
			}
			else gameover = 1;	
		}
		printf("Score: %d", score);
		COORD point;
		point.X = 20;
		point.Y = 31;
		HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hout, point);
		for (i = 0; i < 3; i++) {
			if (lives[i]) printf("%c_%c  ", 253, 253);
			else printf("   ");
		}
		if (score == 300) gameover = 1;
		Sleep(100);
	}
	
	if (score == 300) printf("\nWINNER!");
	else
	printf("\nGAME OVER!");
	int c;
	while(c = getch()) {
		if (c == 13) break;
	}
	
	return 0;
}
