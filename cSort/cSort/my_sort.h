//
//  my_sort.h
//  cSort
//
//  Created by Aakash Chitroda on 4/16/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_sort_h
#define my_sort_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    HEAP_MAX = 0,
    HEAP_MIN
} heap_type__e;

void my_sort__print_array(int32_t nums[], int32_t size);

void my_sort__bubble_sort(int32_t nums[], int32_t size);

void my_sort__bubble_sort_efficient(int32_t nums[], int32_t size);

void my_sort__selection_sort(int32_t nums[], int32_t size);

void my_sort__insertion_sort(int32_t nums[], int32_t size);

void my_sort__shell_sort(int32_t nums[], int32_t size);

void my_sort__quick_sort(int32_t nums[], int32_t start, int32_t end);

void my_sort__merge_sort(int32_t nums[], int32_t start, int32_t end);

void my_sort__heap_sort(int32_t nums[], int32_t size, heap_type__e type);

void my_sort__bucket_sort(int32_t nums[], int32_t size);

#endif /* my_sort_h */
