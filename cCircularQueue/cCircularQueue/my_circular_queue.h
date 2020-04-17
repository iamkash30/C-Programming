//
//  my_circular_queue.h
//  cCircularQueue
//
//  Created by Aakash Chitroda on 4/16/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_circular_queue_h
#define my_circular_queue_h

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int *queue_memory;
    int front_ptr;
    int rear_ptr;
    int queue_capacity;
    int queue_size;
} MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int k);

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value);

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj);

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj);

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj);

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj);

void myCircularQueueFree(MyCircularQueue* obj);


#endif /* my_circular_queue_h */
