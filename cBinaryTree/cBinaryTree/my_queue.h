//
//  my_queue.h
//  cBinaryTree
//
//  Created by Aakash Chitroda on 3/28/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_queue_h
#define my_queue_h

#include <stdio.h>
#include "my_tree.h"

struct queueTreeNode {
    TreeNode *node;
    struct queueTreeNode *next;
};

typedef struct _queue {
    struct queueTreeNode *front, *rear;
} queue;

queue *my_queue__create(void);

void my_queue__push(queue *q, TreeNode *node);

void my_queue__pop(queue *q);

TreeNode *my_queue__top(queue *q);

bool my_queue__empty(queue *q);

#endif /* my_queue_h */
