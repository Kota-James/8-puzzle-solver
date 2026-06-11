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
               temp.x = i;
               temp.y = j; 
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
                temp += abs(i - point.x);
                temp += abs(j - point.y);
            }
        }
    }
    return temp;
}


void display_tiles(Node node){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            printf("%d", node.tiles[i][j]);
        }
        printf("\n");
    }
}