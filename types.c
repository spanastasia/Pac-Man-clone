#include "types.h"

typedef enum {
	WALL,
	TUNNEL,
	PACMAN,
	GHOST	
} Sqrtype;

typedef struct {
	Sqrtype type;
	int visited;
	int x;
	int y;
} Square;
