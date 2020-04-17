//
//  main.c
//  cCircularQueue
//
//  Created by Aakash Chitroda on 4/16/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_circular_queue.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    MyCircularQueue* cQueue = myCircularQueueCreate(3);
    myCircularQueueEnQueue(cQueue, 1) ? printf("Enqueue Success\n") : printf("Enqueue Failed\n");
    myCircularQueueEnQueue(cQueue, 2) ? printf("Enqueue Success\n") : printf("Enqueue Failed\n");
    myCircularQueueEnQueue(cQueue, 3) ? printf("Enqueue Success\n") : printf("Enqueue Failed\n");
    myCircularQueueEnQueue(cQueue, 4) ? printf("Enqueue Success\n") : printf("Enqueue Failed\n");
    printf("Rear: %d\n", myCircularQueueRear(cQueue));
    myCircularQueueIsFull(cQueue) ? printf("Full\n") : printf("Not Full\n");
    myCircularQueueDeQueue(cQueue) ? printf("Dequeue Success\n") : printf("Dequeue Failed\n");
    myCircularQueueEnQueue(cQueue, 4) ? printf("Enqueue Success\n") : printf("Enqueue Failed\n");
    printf("Rear: %d\n", myCircularQueueRear(cQueue));
    printf("Front: %d\n", myCircularQueueFront(cQueue));
    return 0;
}
