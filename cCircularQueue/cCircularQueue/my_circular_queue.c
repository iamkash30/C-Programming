//
//  my_circular_queue.c
//  cCircularQueue
/**
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Your implementation should support following operations:

MyCircularQueue(k): Constructor, set the size of the queue to be k.
Front: Get the front item from the queue. If the queue is empty, return -1.
Rear: Get the last item from the queue. If the queue is empty, return -1.
enQueue(value): Insert an element into the circular queue. Return true if the operation is successful.
deQueue(): Delete an element from the circular queue. Return true if the operation is successful.
isEmpty(): Checks whether the circular queue is empty or not.
isFull(): Checks whether the circular queue is full or not.
 

Example:

MyCircularQueue circularQueue = new MyCircularQueue(3); // set the size to be 3
circularQueue.enQueue(1);  // return true
circularQueue.enQueue(2);  // return true
circularQueue.enQueue(3);  // return true
circularQueue.enQueue(4);  // return false, the queue is full
circularQueue.Rear();  // return 3
circularQueue.isFull();  // return true
circularQueue.deQueue();  // return true
circularQueue.enQueue(4);  // return true
circularQueue.Rear();  // return 4
 
Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Queue library.
 ****/
//  Created by Aakash Chitroda on 4/16/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_circular_queue.h"
#include <stdlib.h>


/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    if (k <= 0) return NULL;
    MyCircularQueue* circular_queue = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    if (!circular_queue) printf("Error: Failed initializing Queue\n");
    else {
        circular_queue->queue_memory = (int *)malloc(sizeof(int) * k);
        if (!circular_queue->queue_memory) printf("Error: Failed allocating Queue memory on Heap\n");
        else {
            circular_queue->front_ptr = -1;
            circular_queue->rear_ptr = -1;
            circular_queue->queue_capacity = k;
            circular_queue->queue_size = 0;
        }
    }
    return circular_queue;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (myCircularQueueIsFull(obj)) return false;
    if (myCircularQueueIsEmpty(obj)) {
        obj->front_ptr = 0;
        obj->rear_ptr = -1;
    }
    obj->rear_ptr = (obj->rear_ptr + 1) % obj->queue_capacity;
    obj->queue_memory[obj->rear_ptr] = value;
    obj->queue_size += 1;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return false;
    obj->queue_memory[obj->front_ptr] = -1;
    obj->front_ptr = (obj->front_ptr + 1) % obj->queue_capacity;
    obj->queue_size -= 1;
    return true;
}
/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (myCircularQueueIsEmpty(obj)) return -1;
    else return obj->queue_memory[obj->front_ptr];
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
  if (myCircularQueueIsEmpty(obj)) return -1;
  else return obj->queue_memory[obj->rear_ptr];
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return (obj->queue_size <= 0);
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return (obj->queue_size >= obj->queue_capacity);
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj) {
        if (obj->queue_memory) {
            free(obj->queue_memory);
            obj->queue_memory = NULL;
        }
        free(obj);
        obj = NULL;
    }
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
