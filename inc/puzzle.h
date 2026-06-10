#ifndef INC_PUZZLE_H_
#define INC_PUZZLE_H_

#include "common.h"

int calc_h0(Node);
int calc_h1(Node);
int calc_h2(Node);

Node move_empty(Node, int); // int -> move direction

int check_goal(Node);

extern const Coordinate GOAL_TILES;

#endif /* INC_PUZZLE_H_ */