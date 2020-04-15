//
//  my_queue.c
//  cQueue
//
//  Created by Aakash Chitroda on 4/14/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_queue.h"

queue__t *my_queue__initialize(void) {
    queue__t *new_queue = (queue__t *)malloc(sizeof(queue__t));
    if (NULL == new_queue) printf("Error: Failed to initialize Queue!\n");
    else {
        new_queue->enqueue =  my_stack__initialize();
        new_queue->dequeue = my_stack__initialize();
    }
    return new_queue;
}

void my_queue__enqueue(queue__t *queue, int32_t val) {
    if (!queue) {
        printf("Error: Queue is not initialized...\n");
        return;
    }
    
    my_stack__push(queue->enqueue, val);
}

int32_t my_queue__dequeue(queue__t *queue) {
    if (!queue) {
        printf("Error: Queue is not initialized...\n");
        return 0;
    }
    int32_t val = 0;
    if (true == my_stack__is_empty(queue->dequeue)) {
        while (!my_stack__is_empty(queue->enqueue)) {
            val = my_stack__top(queue->enqueue);
            my_stack__push(queue->dequeue, val);
            my_stack__pop(queue->enqueue);
        }
    }
    val = my_stack__top(queue->dequeue);
    my_stack__pop(queue->dequeue);
    return val;
}
