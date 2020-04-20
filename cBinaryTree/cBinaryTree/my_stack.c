//
//  my_stack.c
//  cBinaryTree
//
//  Created by Aakash Chitroda on 4/18/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_stack.h"

static stack_tree_node *create_stack_tree_node(TreeNode *node) {
    stack_tree_node *temp = (stack_tree_node *)malloc(sizeof(stack_tree_node));
    if (!temp) return NULL;
    temp->node = node;
    temp->next = NULL;
    return temp;
}

stack *my_stack__create(void) {
    stack *s = (stack *)malloc(sizeof(stack));
    if (!s) return NULL;
    s->top = NULL;
    return s;
}

void my_stack__push(stack *s, TreeNode *node) {
    stack_tree_node *temp = create_stack_tree_node(node);
    if (!s->top) {
        s->top = temp;
        return;
    }
    temp->next = s->top;
    s->top = temp;
}

bool my_stack__empty(stack *s) {
    return s->top == NULL;
}

TreeNode* my_stack__pop(stack *s) {
    TreeNode *top = s->top->node;
    s->top = s->top->next;
    return top;
}

TreeNode *my_stack__top(stack *s) {
    return s->top->node;
}
