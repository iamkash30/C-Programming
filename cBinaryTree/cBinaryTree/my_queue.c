//
//  my_queue.c
//  cBinaryTree
//
//  Created by Aakash Chitroda on 3/28/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_queue.h"

static struct queueTreeNode* create_queue_treeNode(TreeNode *node) {
    struct queueTreeNode *q_node = (struct queueTreeNode *)malloc(sizeof(struct queueTreeNode));
    if (NULL != q_node) {
        q_node->node = node;
        q_node->next = NULL;
    }
    return q_node;
}

queue *my_queue__create(void) {
    queue *newQueue = (queue *)malloc(sizeof(queue));
    if (NULL != newQueue) {
        newQueue->front = newQueue->rear = NULL;
    }
    return newQueue;
}

void my_queue__push(queue *q, TreeNode *node) {
    struct queueTreeNode *q_node = create_queue_treeNode(node);
    if (NULL == q_node) {
        fprintf(stderr, "Failed to push. Queue is not initialized!\n");
        return;
    }
    
    // If Queue is empty
    if (NULL == q->rear) {
        q->front = q->rear = q_node;
        return;
    }
    // Add node at the end of queue
    q->rear->next = q_node;
    q->rear = q->rear->next;
}

void my_queue__pop(queue *q) {
    if (NULL == q->front) {
        fprintf(stderr, "Failed to pop. Queue is already empty\n");
        return;
    }
    
    // Move to q->front to next
    q->front = q->front->next;
    if (NULL == q->front) q->rear = NULL;
    return;
}

TreeNode *my_queue__top(queue *q) {
    if (NULL == q->front) {
        fprintf(stderr, "Failed to top. Queue is empty!\n");
        return NULL;
    }
    return q->front->node;
}

bool my_queue__empty(queue *q) {
    if (NULL == q->front)
        return true;
    return false;
}
