//
//  my_stack.h
//  cQueue
//
//  Created by Aakash Chitroda on 4/15/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_stack_h
#define my_stack_h

#include <stdio.h>
#include <stdbool.h>

typedef struct _stack_node {
    int32_t val;
    struct _stack_node *next;
} stack_node__t;

typedef struct {
    stack_node__t *top;
} stack__t;

stack__t *my_stack__initialize(void);

bool my_stack__is_empty(stack__t *stack);


void my_stack__push(stack__t *stack, int32_t val);

void my_stack__pop(stack__t *stack);

int32_t my_stack__top(stack__t *stack);

#endif /* my_stack_h */
