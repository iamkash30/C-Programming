//
//  main.c
//  cQueue
//
//  Created by Aakash Chitroda on 4/14/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_queue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    queue__t *queue = NULL;
    queue = my_queue__initialize();
    my_queue__enqueue(queue, 1);
    my_queue__enqueue(queue, 2);
    my_queue__enqueue(queue, 3);
    my_queue__enqueue(queue, 4);
    printf("Dequeue: %d\n", my_queue__dequeue(queue));
    printf("Dequeue: %d\n", my_queue__dequeue(queue));
    printf("Dequeue: %d\n", my_queue__dequeue(queue));
    printf("Dequeue: %d\n", my_queue__dequeue(queue));
    printf("Dequeue: %d\n", my_queue__dequeue(queue));
    return 0;
}
