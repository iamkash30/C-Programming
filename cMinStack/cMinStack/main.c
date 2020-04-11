//
//  main.c
//  cMinStack
//
//  Created by Aakash Chitroda on 4/10/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "min_stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    min_stack_t *my_stack = min_stack__create();
    min_stack__push(my_stack, 50);
    min_stack__push(my_stack, 40);
    min_stack__push(my_stack, 35);
    min_stack__push(my_stack, 55);
    min_stack__push(my_stack, 37);
    min_stack__push(my_stack, 20);
    printf("Get Min: %d\n", min_stack__get_min(my_stack));
    printf("Get Top: %d\n", min_stack__top(my_stack));
    min_stack__pop(my_stack);
    printf("Get Min: %d\n", min_stack__get_min(my_stack));
    printf("Get Top: %d\n", min_stack__top(my_stack));
    min_stack__free(my_stack);
    return 0;
}
