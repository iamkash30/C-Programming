//
//  my_stack.c
//  cQueue
//
//  Created by Aakash Chitroda on 4/15/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_stack.h"
#include <stdlib.h>

static stack_node__t *create_new_stack_node(int32_t val) {
    stack_node__t *new_stack_node = (stack_node__t *)malloc(sizeof(stack_node__t));
    if (NULL == new_stack_node) printf("Error: Failed to create new stack node\n");
    else {
        new_stack_node->val = val;
        new_stack_node->next = NULL;
    }
    return new_stack_node;
}

stack__t *my_stack__initialize(void) {
    stack__t *new_stack = (stack__t *)malloc(sizeof(stack__t));
    if (NULL == new_stack) printf("Error: Failed to initialize Stack!\n");
    else new_stack->top = NULL;
    return new_stack;
}

bool my_stack__is_empty(stack__t *stack) {
    return stack->top == NULL;
}

void my_stack__push(stack__t *stack, int32_t val) {
    if (!stack) {
        printf("Error: Stack is not initialized...\n");
        return;
    }
    stack_node__t *stack_node = create_new_stack_node(val);
    
    if (NULL == stack_node) exit(1);
    
    stack_node->next = stack->top;
    
    stack->top = stack_node;
    
    return;
}


void my_stack__pop(stack__t *stack) {
    if (!stack) {
        printf("Error: Stack is not initialized...\n");
        return;
    }
    
    if (true == my_stack__is_empty(stack)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    
    stack_node__t *temp = stack->top;
    
    stack->top = stack->top->next;
    
    temp->next = NULL;
    
    free(temp);

}

int32_t my_stack__top(stack__t *stack) {
    if (!stack) {
        printf("Error: Stack is not initialized...\n");
        return 0;
    }
    if (true == my_stack__is_empty(stack)) {
        printf("Error: Cannot TOP, Stack is Empty\n");
        exit(1);
    }
    return stack->top->val;
}
