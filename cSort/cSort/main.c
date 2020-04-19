//
//  main.c
//  cSort
//
//  Created by Aakash Chitroda on 4/16/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_sort.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int32_t num[] = {5,3,1,2,4,7,9,6,1,10};
    int32_t size = sizeof(num) / sizeof(num[0]);
    my_sort__print_array(num, size);
    my_sort__bubble_sort_efficient(num, size);
    my_sort__print_array(num, size);
    return 0;
}
