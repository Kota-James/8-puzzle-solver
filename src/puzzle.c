#include "../inc/common.h"
#include "../inc/puzzle.h"
#include <stdlib.h>

const char GOAL_TILES[SIZE][SIZE] = {
        {1, 2, 3},
        {8, 0, 4},
        {7, 6, 5}
};

Point position(Node node, int target){
    Point temp = {-1, -1};
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(node.tiles[i][j] == target){
               temp.x = j;  // x = 列(横)
               temp.y = i;  // y = 行(縦)
               return temp;
            }
        }
    }
    return temp;
}

int calc_h0(Node node){
    return 0;   
}

int calc_h1(Node node){
    int temp = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(!(node.tiles[i][j] == GOAL_TILES[i][j])){
                temp++;
            }
        }
    }
    if(!(node.tiles[1][1] == 0)){
        temp--;
    }
    return temp;
}

int calc_h2(Node node){
    int temp = 0;
    // int target = 1;
    Point point;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            point = position(node, GOAL_TILES[i][j]);
            if(GOAL_TILES[i][j] != 0){
                temp += abs(i - point.y);  // 行差
                temp += abs(j - point.x);  // 列差
            }
        }
    }
    return temp;
}

int can_move(Point p){
    int flags = 0;
    if(p.x > 0)     flags |= DIR_WEST;
    if(p.x < SIZE-1) flags |= DIR_EAST;
    if(p.y > 0)     flags |= DIR_NORTH;
    if(p.y < SIZE-1) flags |= DIR_SOUTH;
    return flags;
}

Node move_empty(Node node, int dir){
    Node next = node;

    int next_x = node.empty.x;  // x = 列(横)
    int next_y = node.empty.y;  // y = 行(縦)

    if(dir == DIR_NORTH) next_y--;
    else if(dir == DIR_SOUTH) next_y++;
    else if(dir == DIR_EAST) next_x++;
    else if(dir == DIR_WEST) next_x--;

    char temp = node.tiles[node.empty.y][node.empty.x];
    next.tiles[node.empty.y][node.empty.x] = node.tiles[next_y][next_x];
    next.tiles[next_y][next_x] = temp;

    next.empty.x = next_x;
    next.empty.y = next_y;
    next.last_move = dir;
    next.g = node.g + 1;
    next.h = calc_h2(next);
    next.f = next.g + next.h;
    
    return next;
}


int check_goal(Node node){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(node.tiles[i][j] != GOAL_TILES[i][j]){
                return 0;
            }
        }
    }
    return 1;
}


void display_tiles(Node node){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d", node.tiles[i][j]);
        }
        printf("\n");
    }
}