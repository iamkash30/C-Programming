//
//  min_stack.c
//  cMinStack
//
//  Created by Aakash Chitroda on 4/10/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
#include "min_stack.h"

static const int32_t DEFAULT_STACK_SIZE = 512;

static stack_node_t *min_stack__create_stack_node(int32_t stack_capacity) {
    stack_node_t *stack_node = (stack_node_t *)malloc(sizeof(stack_node_t));
    if (NULL == stack_node) {
        fprintf(stderr, "Error: Allocating memory for stack node failed!\n");
        return NULL;
    }
    stack_node->stack_memory = (int32_t *)malloc(sizeof(int32_t) * stack_capacity);
    if (NULL == stack_node->stack_memory) {
        fprintf(stderr, "Error: Allocating stack memory failed!\n");
        return NULL;
    }
    stack_node->stack_capacity = stack_capacity;
    stack_node->stack_pointer = -1;
    stack_node->stack_size = 0;
    return stack_node;
}

min_stack_t* min_stack__create(void) {
    min_stack_t *stack = NULL;
    stack = (min_stack_t *)malloc(sizeof(min_stack_t));
    if (stack != NULL) {
        stack->main_stack = min_stack__create_stack_node(DEFAULT_STACK_SIZE);
        if (NULL == stack->main_stack) {
            fprintf(stderr, "Error: Initializing Main Stack Failed!\n");
            return NULL;
        }
        stack->min_stack = min_stack__create_stack_node(DEFAULT_STACK_SIZE);
        if (NULL == stack->min_stack) {
            fprintf(stderr, "Error: Initializing Min Stack Failed!\n");
            return NULL;
        }
    }
    return stack;
}

void min_stack__push(min_stack_t* obj, int32_t val) {
    if (NULL == obj) {
        fprintf(stderr, "Error: Stack is not initiliazed!\n");
        return;
    }
    obj->main_stack->stack_memory[++obj->main_stack->stack_pointer] = val;
    obj->main_stack->stack_size += 1;
    
    if (obj->min_stack->stack_pointer < 0) {
        obj->min_stack->stack_memory[++obj->min_stack->stack_pointer] = val;
        obj->min_stack->stack_size += 1;
    } else {
        if (min_stack__top(obj) < min_stack__get_min(obj)) {
            obj->min_stack->stack_memory[++obj->min_stack->stack_pointer] = val;
            obj->min_stack->stack_size += 1;
        }
    }
}

int32_t min_stack__top(min_stack_t* obj) {
    return obj->main_stack->stack_memory[obj->main_stack->stack_pointer];
}

int32_t min_stack__get_min(min_stack_t* obj) {
    return obj->min_stack->stack_memory[obj->min_stack->stack_pointer];
}

void min_stack__pop(min_stack_t* obj) {
    int32_t top_element = min_stack__top(obj);
    obj->main_stack->stack_pointer -= 1;
    obj->main_stack->stack_size -= 1;
    if (top_element == min_stack__get_min(obj)) {
        obj->min_stack->stack_pointer -= 1;
        obj->min_stack->stack_size -= 1;
    }
}

void min_stack__free(min_stack_t* obj) {
    if (obj) {
        if (obj->main_stack) {
            if (obj->main_stack->stack_memory) {
                free(obj->main_stack->stack_memory);
            }
            free(obj->main_stack);
        }
        
        if (obj->min_stack) {
            if (obj->min_stack->stack_memory) {
                free(obj->min_stack->stack_memory);
            }
            free(obj->min_stack);
        }
    }
    free(obj);
}
