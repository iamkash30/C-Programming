//
//  main.c
//  cMinStack
//
//  Created by Aakash Chitroda on 4/10/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    stack__t *my_stack = NULL;
    my_stack = stack__create();
    stack__push(my_stack, 5);
    stack__push(my_stack, 2);
    stack__push(my_stack, 6);
    stack__push(my_stack, 1);
    stack__push(my_stack, 3);
    printf("Min Element: %d\n", stack__get_min(my_stack));
    printf("Max Element: %d\n", stack__get_max(my_stack));
    printf("Top Element: %d\n", stack__top(my_stack));
    stack__pop(my_stack);
    stack__pop(my_stack);
    stack__pop(my_stack);
    printf("Min Element: %d\n", stack__get_min(my_stack));
    printf("Max Element: %d\n", stack__get_max(my_stack));
    printf("Top Element: %d\n", stack__top(my_stack));
    return 0;
}
