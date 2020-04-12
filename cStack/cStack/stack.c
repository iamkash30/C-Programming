//
//  min_stack.c
//  cMinStack
//
//  Created by Aakash Chitroda on 4/10/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//
/**
 * Your (stack__t) struct will be instantiated and called as such:
 * stack__t* obj = stack__create();
 * stack__push(obj, x);
 
 * stack__pop(obj);
 
 * int param_3 = stack__top(obj);
 
 * int param_4 = stack__get_min(obj);
 
 * stack__free(obj);
*/
#include "stack.h"

#define STACK_OVERFLOW              0
#define STACK_IS_EMPTY              1
#define STACK_NODE_FAILED           2
#define STACK_MEMORY_FAILED         3
#define MAIN_STACK_FAILED           4
#define MIN_STACK_FAILED            5
#define MAX_STACK_FAILED            6
#define STACK_IS_NOT_INITIALIZED    7

static const int32_t DEFAULT_STACK_SIZE = 1024;

static const uint8_t ERROR_MSG[][64] = {
  "Error: Stack Overflow!",
    "Error: Stack is Empty!",
    "Error: Allocating memory for stack node failed!",
    "Error: Allocating stack memory failed",
    "Error: Initializing Main Stack failed!",
    "Error: Initializing Min Stack failed!",
    "Error: Initializing Max Stack failed!",
    "Error: Stack is not initialized!",
};

#define PRINT_ERROR(error_num) \
    fprintf(stderr, "Info: %s: Line: %d: %s: ", __FILE__, __LINE__, __FUNCTION__); \
    fprintf(stderr, "%s\n", ERROR_MSG[error_num]);


static stack_node__t *stack__create_stack_node(int32_t stack_capacity) {
    stack_node__t *stack_node = (stack_node__t *)malloc(sizeof(stack_node__t));
    if (NULL == stack_node) {
        PRINT_ERROR(STACK_NODE_FAILED);
        return NULL;
    }
    stack_node->stack_memory = (int32_t *)malloc(sizeof(int32_t) * stack_capacity);
    if (NULL == stack_node->stack_memory) {
        PRINT_ERROR(STACK_MEMORY_FAILED);
        return NULL;
    }
    stack_node->stack_capacity = stack_capacity;
    stack_node->stack_pointer = -1;
    stack_node->stack_size = 0;
    return stack_node;
}

stack__t* stack__create(void) {
    stack__t *stack = NULL;
    stack = (stack__t *)malloc(sizeof(stack__t));
    if (stack != NULL) {
        stack->main_stack = stack__create_stack_node(DEFAULT_STACK_SIZE);
        if (NULL == stack->main_stack) {
            PRINT_ERROR(MAIN_STACK_FAILED);
            return NULL;
        }
        
        stack->min_stack = stack__create_stack_node(DEFAULT_STACK_SIZE);
        if (NULL == stack->min_stack) {
            PRINT_ERROR(MIN_STACK_FAILED);
            return NULL;
        }
        
        stack->max_stack = stack__create_stack_node(DEFAULT_STACK_SIZE);
        if (NULL == stack->min_stack) {
            PRINT_ERROR(MAX_STACK_FAILED);
            return NULL;
        }
    }
    return stack;
}

bool stack__is_empty(stack__t* obj) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return false;
    }
    return (0 == obj->main_stack->stack_size);
}

bool stack__is_full(stack__t* obj) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return false;
    }
    return (obj->main_stack->stack_capacity == obj->main_stack->stack_size);
}

int32_t stack__top(stack__t* obj) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return 0;
    }
    
    if (stack__is_empty(obj)) {
        PRINT_ERROR(STACK_IS_EMPTY);
        return 0;
    }
    return obj->main_stack->stack_memory[obj->main_stack->stack_pointer];
}

int32_t stack__get_min(stack__t* obj) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return 0;
    }
    if (obj->min_stack->stack_pointer < 0) {
        return 0;
    }
    
    return obj->min_stack->stack_memory[obj->min_stack->stack_pointer];
}

int32_t stack__get_max(stack__t* obj) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return 0;
    }
    if (obj->max_stack->stack_pointer < 0) {
        return 0;
    }
    
    return obj->max_stack->stack_memory[obj->max_stack->stack_pointer];
}

static void stack__push_on_main_stack(stack__t* obj, int32_t val) {
    obj->main_stack->stack_memory[++obj->main_stack->stack_pointer] = val;
    obj->main_stack->stack_size += 1;
}

static void stack__push_on_min_stack(stack__t* obj, int32_t val) {
    if (obj->min_stack->stack_pointer < 0) {
        obj->min_stack->stack_memory[++obj->min_stack->stack_pointer] = val;
        obj->min_stack->stack_size += 1;
    } else {
        if (stack__top(obj) <= stack__get_min(obj)) {
            obj->min_stack->stack_memory[++obj->min_stack->stack_pointer] = val;
            obj->min_stack->stack_size += 1;
        }
    }
}

static void stack__push_on_max_stack(stack__t* obj, int32_t val) {
    if (obj->max_stack->stack_pointer < 0) {
        obj->max_stack->stack_memory[++obj->max_stack->stack_pointer] = val;
        obj->max_stack->stack_size += 1;
    } else {
        if (stack__top(obj) >= stack__get_max(obj)) {
            obj->max_stack->stack_memory[++obj->max_stack->stack_pointer] = val;
            obj->max_stack->stack_size += 1;
        }
    }
}

void stack__push(stack__t* obj, int32_t val) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return;
    }
    
    if (stack__is_full(obj)) {
        PRINT_ERROR(STACK_OVERFLOW);
        return;
    }
    
    // Push in main stack first
    stack__push_on_main_stack(obj, val);
    
    // Check and Push in min stack
    stack__push_on_min_stack(obj, val);
    
    // Check and Push in max stack
    stack__push_on_max_stack(obj, val);
}

static void stack__pop_from_min_stack(int32_t main_stack_top_element, stack__t *obj) {
    if (main_stack_top_element == stack__get_min(obj)) {
        obj->min_stack->stack_pointer -= 1;
        obj->min_stack->stack_size -= 1;
    }
}

static void stack__pop_from_max_stack(int32_t main_stack_top_element, stack__t *obj) {
    if (main_stack_top_element == stack__get_max(obj)) {
        obj->max_stack->stack_pointer -= 1;
        obj->max_stack->stack_size -= 1;
    }
}

void stack__pop(stack__t* obj) {
    if (NULL == obj) {
        PRINT_ERROR(STACK_IS_NOT_INITIALIZED);
        return;
    }
    
    if (stack__is_empty(obj)) {
        PRINT_ERROR(STACK_IS_EMPTY);
        return;
    }
    int32_t top_element = stack__top(obj);
    obj->main_stack->stack_pointer -= 1;
    obj->main_stack->stack_size -= 1;
    
    // Pop from min stack if TOP pf main stack is equal
    stack__pop_from_min_stack(top_element, obj);
    
    // Pop from max stack if TOP of main stack is equal
    stack__pop_from_max_stack(top_element, obj);
    
}

static void stack__free_stack_memory(int32_t *stack_memory) {
    if (stack_memory) {
        free(stack_memory);
        stack_memory = NULL; // If you don't make the object point to NULL, it will be dangling pointer
    }
}

static void stack__free_stack_node_obj(stack_node__t *stack_node_obj) {
    if (stack_node_obj) {
        stack__free_stack_memory(stack_node_obj->stack_memory);
        free(stack_node_obj);
        stack_node_obj = NULL; // If you don't make the object point to NULL, it will be dangling pointer
    }
}

void stack__free(stack__t* obj) {
    if (obj) {
        if (obj->main_stack) stack__free_stack_node_obj(obj->main_stack);
        
        if (obj->min_stack) stack__free_stack_node_obj(obj->min_stack);
        
        if (obj->max_stack) stack__free_stack_node_obj(obj->max_stack);
    }
    free(obj);
    obj = NULL; // If you don't make the object point to NULL, it will be dangling pointer
}


