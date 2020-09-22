#include "user_lib.h"


int leaveHome(Square* ghost) {
	if ((ghost->x > 13 && ghost->x < 16) && ghost->y == 14) {
		ghost->x--;
		return 0;
	}
	if (ghost->x == 13 && (ghost->y > 11 && ghost->y < 15)) {
		ghost->y--;
		return 0;
	}
	return 1;
}

