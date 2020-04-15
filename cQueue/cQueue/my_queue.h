//
//  my_queue.h
//  cQueue
//
//  Created by Aakash Chitroda on 4/14/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_queue_h
#define my_queue_h

#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"

struct _queue {
    stack__t *enqueue, *dequeue;
};

typedef struct _queue queue__t;

queue__t *my_queue__initialize(void);

void my_queue__enqueue(queue__t *queue, int32_t val);

int32_t my_queue__dequeue(queue__t *queue);


#endif /* my_queue_h */
