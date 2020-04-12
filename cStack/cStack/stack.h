//
//  min_stack.h
//  cMinStack
//
//  Created by Aakash Chitroda on 4/10/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef min_stack_h
#define min_stack_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _stack_node{
    int32_t *stack_memory;
    int32_t stack_pointer;
    int32_t stack_capacity;
    int32_t stack_size;
} stack_node__t;

typedef struct {
    stack_node__t *main_stack, *min_stack, *max_stack;
} stack__t;

/** initialize your data structure here. */

stack__t* stack__create(void);

void stack__push(stack__t* obj, int32_t val);

void stack__pop(stack__t* obj);

int32_t stack__top(stack__t* obj);

int32_t stack__get_min(stack__t* obj);

int32_t stack__get_max(stack__t* obj);

bool stack__is_empty(stack__t* obj);

bool stack__is_full(stack__t* obj);

void stack__free(stack__t* obj);

#endif /* min_stack_h */
