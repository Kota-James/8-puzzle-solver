#ifndef INC_PUZZLE_H_
#define INC_PUZZLE_H_

#include "common.h"

Point position(Node, int);

int calc_h0(Node);
int calc_h1(Node);
int calc_h2(Node);

Node move_empty(Node, int); // int -> move direction

int check_goal(Node);

void display_tiles(Node);

extern const char GOAL_TILES[SIZE][SIZE];

#endif /* INC_PUZZLE_H_ */