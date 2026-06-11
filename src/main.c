#include "../inc/common.h"
#include "../inc/puzzle.h"
#include "../inc/search.h"

#define MAIN_C_

int main(void){
Node test = {
        .tiles = {
            {{5, 7, 8}, {3, 4, 0}, {2, 6, 1}}
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
    
    return 0;
}