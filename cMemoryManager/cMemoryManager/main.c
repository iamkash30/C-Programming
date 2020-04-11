//
//  main.c
//  cMemoryManager
//
//  Created by Aakash Chitroda on 4/8/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_memory_manager.h"
#include <stdlib.h>
#include <string.h>

#define my_mem__sizeof(type) (void *)(&type + 1) - (void *)(&type)

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char *buff = (char *)my_mem__malloc(8);
    if (buff != NULL) {
        printf("Memory allocation successful\n");
    } else {
        printf("Memory allocation failed\n");
    }
    my_mem__free(buff);
    print_mem_list();
    
    int arr[5] = {1,2,3,4,5};
    printf("&arr = %p\n", (void *)&arr);
    printf("&arr = %p\n", (void *)(&arr+1));
    printf("My_sizeof: %lu\n", my_mem__sizeof(arr));
    return 0;
}
