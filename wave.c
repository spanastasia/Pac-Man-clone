#include "user_lib.h"
#define BLANK -2
#define WALL -1

//Initialize wave matrix
void intilizeWaveMatrix(int arr[LEN][WID], int grid[LEN][WID]) {
	int i, j;

	for(i = 0; i < LEN; i++) {
		for (j = 0; j < WID; j++) {
			if (!arr[i][j]) grid[i][j] = BLANK;
			else grid[i][j] = WALL;
		}
	}
}
//Looks for the shortest way and returns 1. If there is no way from point a to point b returns 0
int lee(int ax, int ay, int bx, int by, int grid[LEN][WID], int px[LEN*WID], int py[LEN*WID]) {
  int dx[4] = {1, 0, -1, 0}; //Sets the offset
  int dy[4] = {0, 1, 0, -1};
  int d, x, y, k, len;
  int stop;

  if (grid[ay][ax] == WALL || grid[by][bx] == WALL) return 0;

  d = 0;
  grid[ay][ax] = 0; //Sets start point value 0
  do {
    stop = 1;
    for ( y = 0; y < LEN; ++y )
      for ( x = 0; x < WID; ++x )
        if ( grid[y][x] == d ) { //square(x, y) gets value d
        
        	for ( k = 0; k < 4; ++k ) { //all neibors gets value d+1
            	int iy=y + dy[k], ix = x + dx[k];
            	if ( iy >= 0 && iy < LEN && ix >= 0 && ix < WID && grid[iy][ix] == BLANK ) {
                	stop = 0;
                	grid[iy][ix] = d + 1;
            	}
        	}
        }
    d++;
  } while ( !stop && grid[by][bx] == BLANK );

  if (grid[by][bx] == BLANK) return 0;


  len = grid[by][bx];   //Way recovery    
  x = bx;
  y = by;
  d = len;
  while ( d > 0 ) {
    px[d] = x;
    py[d] = y; 
    d--;
    for (k = 0; k < 4; ++k) {
       int iy=y + dy[k], ix = x + dx[k];
       if ( iy >= 0 && iy < LEN && ix >= 0 && ix < WID && grid[iy][ix] == d) {
          x = x + dx[k];
          y = y + dy[k];
          break;
    	}
    }
  }
  px[0] = ax;
  py[0] = ay;
  return 1;
}
