#ifndef INC_COMMON_H_
#define INC_COMMON_H_

#include "stdio.h"
#include "stdint.h"


#define SIZE 3
#define MAX_NODES 1000000

#define DIR_NORTH 0
#define DIR_SOUTH 1
#define DIR_EAST  2
#define DIR_WEST  3

typedef struct{
    char tiles[SIZE][SIZE];
}Coordinate;

typedef struct{
    int x;
    int y;
}Point;

typedef struct{
    Coordinate tiles;
    Point empty;
    int g;  // cost from start
    int h;  // estimated cost to goal
    int f;  // g + h
}Node;

/*
// Coordinate
(0, 2) (1, 2) (2, 2) 

(0, 1) (1, 1) (2, 1) 

(0, 0) (1, 0) (2, 0) 
*/

/*
// goal
1 2 3
8   4
7 6 5
*/

#endif /* INC_COMMON_H_ */