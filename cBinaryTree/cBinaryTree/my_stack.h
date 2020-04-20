//
//  my_stack.h
//  cBinaryTree
//
//  Created by Aakash Chitroda on 4/18/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_stack_h
#define my_stack_h

#include <stdio.h>
#include "my_tree.h"

typedef struct _stack_tree_node {
    TreeNode *node;
    struct _stack_tree_node *next;
}stack_tree_node;

typedef struct _stack {
    stack_tree_node *top;
} stack;

stack *my_stack__create(void);

void my_stack__push(stack *s, TreeNode *node);

TreeNode *my_stack__pop(stack *s);

TreeNode *my_stack__top(stack *s);

bool my_stack__empty(stack *s);

#endif /* my_stack_h */
