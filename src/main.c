#include "../inc/common.h"
#include "../inc/puzzle.h"
#include "../inc/search.h"

#define MAIN_C_

int main(void){
Node test = {
        .tiles = {
            {5, 7, 8},
            {3, 4, 0},
            {2, 6, 1}
        // {1, 2, 3},
        // {8, 0, 4},
        // {7, 6, 5}
        },
        .empty = {2, 1},
        .last_move = 0,
        .g = 0
    };
    display_tiles(test);
    
    test.h = calc_h0(test);
    printf("h0 = %d\n", test.h);
    
    test.h = calc_h1(test);
    printf("h1 = %d\n", test.h);
    
    test.h = calc_h2(test);
    printf("h2 = %d\n", test.h);

    printf("ifgoal %d\n", check_goal(test));
//
    test = move_empty(test, DIR_SOUTH);
    display_tiles(test);
    test.h = calc_h0(test);
    printf("h0 = %d\n", test.h);
    test.h = calc_h1(test);
    printf("h1 = %d\n", test.h);
    test.h = calc_h2(test);
    printf("h2 = %d\n", test.h);
    printf("ifgoal %d\n", check_goal(test));
//
    test = move_empty(test, DIR_WEST);
    display_tiles(test);
    test.h = calc_h0(test);
    printf("h0 = %d\n", test.h);
    test.h = calc_h1(test);
    printf("h1 = %d\n", test.h);
    test.h = calc_h2(test);
    printf("h2 = %d\n", test.h);
    printf("ifgoal %d\n", check_goal(test));
//
    test = move_empty(test, DIR_NORTH);
    display_tiles(test);
    test.h = calc_h0(test);
    printf("h0 = %d\n", test.h);
    test.h = calc_h1(test);
    printf("h1 = %d\n", test.h);
    test.h = calc_h2(test);
    printf("h2 = %d\n", test.h);
    printf("ifgoal %d\n", check_goal(test));


    // printf("can_move 0x%04x\n", can_move((Point){1,1}));
    // printf("can_move 0x%04x\n", can_move((Point){0,0}));
    // printf("can_move 0x%04x\n", can_move((Point){1,2}));
    // printf("can_move 0x%04x\n", can_move((Point){2,1}));

    
    return 0;
}