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
} stack_node_t;

typedef struct _min_stack_t{
    stack_node_t *main_stack, *min_stack;
} min_stack_t;

/** initialize your data structure here. */

min_stack_t* min_stack__create(void);

void min_stack__push(min_stack_t* obj, int32_t val);

void min_stack__pop(min_stack_t* obj);

int32_t min_stack__top(min_stack_t* obj);

int32_t min_stack__get_min(min_stack_t* obj);

void min_stack__free(min_stack_t* obj);



#endif /* min_stack_h */
