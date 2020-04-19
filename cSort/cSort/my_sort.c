//
//  my_sort.c
//  cSort
//
//  Created by Aakash Chitroda on 4/16/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_sort.h"

//a = 4, b = 3
static void my_sort__swap(int32_t *a, int32_t *b) {
    int32_t temp = *a;
    *a = *b;
    *b = temp;
}

void my_sort__print_array(int32_t nums[], int32_t size) {
    printf("\n");
    for (int32_t i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

/**
 B U B B L E    S O R T
 PERFORMANCE:
 Worst Case: O(n^2)
 Best Case: O(n^2)
 Avg Case: O(n^2)
 */
void my_sort__bubble_sort(int32_t nums[], int32_t size) {
    for (int32_t j = size - 1; j >= 0; j--) {
        for (int32_t i = 0; i < j; i++) {
            if (nums[i] > nums[i+1]) my_sort__swap(&nums[i], &nums[i+1]);
        }
    }
}

/**
B U B B L E    S O R T    I M P R O V E D
PERFORMANCE:
Worst Case: O(n^2)
Best Case: O(n)
Avg Case: O(n^2)
*/
void my_sort__bubble_sort_efficient(int32_t nums[], int32_t size) {
    bool is_swapped = true;
    for (int32_t j = size - 1; j >= 0 && is_swapped; j--) {
        is_swapped = false;
        for (int32_t i = 0; i < j; i++) {
            if (nums[i] > nums[i+1]) {
                my_sort__swap(&nums[i], &nums[i+1]);
                is_swapped = true;
            }
        }
    }
}

/**
 S E L E C T I O N    S O R T
 In-place sorting algorithm
 1. Find the minimum value in the list
 2. Swap it with the value in the current position
 3. Repeat until the entire array is sorted
 
 PERFORMACE:
 Worst Case: O(n^2)
 Best Case: O(n^2)
 Avg Case: O(n^2)
 */

static int32_t my_sort__find_min_value_index(int32_t nums[], int32_t index, int32_t size) {
    int32_t min = index;
    for (int32_t i = index + 1; i < size; i++) {
        if (nums[min] > nums[i])
            min = i;
    }
    return min;
}
void my_sort__selection_sort(int32_t nums[], int32_t size) {
    for (int32_t i = 0; i < size; i++) {
        int32_t min = my_sort__find_min_value_index(nums, i, size);
        if (min != i) my_sort__swap(&nums[min], &nums[i]);
    }
}

/**
 I N S E R T I O N    S O R T
 PERFORMACE:
 Worst Case: O(n^2)
 Best Case: O(n)
 Avg Case: O(n^2)
 */
void my_sort__insertion_sort(int32_t nums[], int32_t size) {
    int32_t unsorted_pos = 0, sorted_pos = 0;
    int32_t unsorted_val = 0;
    
    for (unsorted_pos = 1; unsorted_pos < size; unsorted_pos++) {
        unsorted_val = nums[unsorted_pos];
        sorted_pos = unsorted_pos;
        while ((sorted_pos > 0) && (nums[sorted_pos-1] > unsorted_val)) {
            nums[sorted_pos] = nums[sorted_pos-1];
            sorted_pos--;
        }
        nums[sorted_pos] = unsorted_val;
    }
}

/**
S H E L L    S O R T
PERFORMACE:
Worst Case: O(n^2)
Best Case: O(n)
Avg Case: O(n^2)
*/
void my_sort__shell_sort(int32_t nums[], int32_t size){
    int32_t i = 0, j = 0, gap = 0;
    for (gap = size/2; gap > 0; gap /= 2)
        for (j = gap; j < size; j++)
            for (i = j-gap; i >= 0; i -= gap) {
                if (nums[i] > nums[i+gap]) my_sort__swap(&nums[i], &nums[i+gap]);
                else break;
            }
}

/**
Q U I C K    S O R T
PERFORMACE:
Worst Case: O()
Best Case: O()
Avg Case: O()
*/
static int32_t my_sort__quick_sort_partition(int32_t nums[], int32_t start, int32_t end) {
    int32_t i, j, pivot;
    pivot = nums[start];
    i = start;
    j = end;
    while (i < j) {
        do {
            i++;
        } while ((i < end) && (pivot >= nums[i]));
        
        do {
            j--;
        } while ((j > start) && (pivot < nums[j]));
        
        if (i < j) {
            my_sort__swap(&nums[i], &nums[j]);
        }
    }
    my_sort__swap(&nums[start], &nums[j]);
    return j;
}

void my_sort__quick_sort(int32_t nums[], int32_t start, int32_t end) {
    if (start < end) {
        int32_t mid = my_sort__quick_sort_partition(nums, start, end);
        printf("Sorted Pos: %d\n", mid);
        my_sort__quick_sort(nums, start, mid);
        my_sort__quick_sort(nums, mid+1, end);
    }
}

/**
M E R G E    S O R T
PERFORMACE:
Worst Case: O()
Best Case: O()
Avg Case: O()
*/
static void my_sort__merge_sort_partition(int32_t nums[], int32_t low, int32_t mid, int32_t high) {
    int32_t i, j, k, array_1_size, array_2_size;
    array_1_size = array_2_size = i = j = k = 0;
    array_1_size = mid - low + 1;
    array_2_size = high - mid;
    int32_t array_1[array_1_size];
    int32_t array_2[array_2_size];
    
    for (i = 0; i < array_1_size; i++) array_1[i] = nums[low + i];
    
    for (j = 0; j < array_2_size; j++) array_2[j] = nums[mid + j + 1];
    i = j = 0;
    k = low;
    
    while (i < array_1_size && j < array_2_size) {
        if (array_1[i] < array_2[j]) nums[k++] = array_1[i++];
        else nums[k++] = array_2[j++];
    }
    
    while (i < array_1_size) nums[k++] = array_1[i++];
    while (j < array_2_size) nums[k++] = array_2[j++];
    return;
}

void my_sort__merge_sort(int32_t nums[], int32_t start, int32_t end) {
    if (start < end) {
        int32_t mid = (start + end) / 2;
        my_sort__merge_sort(nums, start, mid);
        my_sort__merge_sort(nums, mid + 1, end);
        my_sort__merge_sort_partition(nums, start, mid, end);
    }
}

/**
H E A P    S O R T
PERFORMACE:
Worst Case: O(nlog(n))
Best Case: O(nlog(n))
Avg Case: O(nlog(n))
*/
static int32_t my_sort__get_parent(int32_t child) {
    return ((child / 2) - 1);
}

static int32_t my_sort__get_left_child(int32_t parent) {
    return ((2 * parent) + 1);
}

static int32_t my_sort__get_right_child(int32_t parent) {
    return ((2 * parent) + 2);
}

static void my_sort__max_heapify(int32_t nums[], int32_t size, int32_t actual_parent) {
    int32_t new_parent = actual_parent;
    int32_t left_child, right_child;
    left_child = my_sort__get_left_child(new_parent);
    right_child = my_sort__get_right_child(new_parent);
    
    if ((left_child < size) && (nums[left_child] > nums[new_parent])) new_parent = left_child;
    
    if ((right_child < size) && (nums[right_child] > nums[new_parent])) new_parent = right_child;
    
    if (new_parent != actual_parent) {
        // Swap child with its parent if child is greater than parent
        my_sort__swap(&nums[actual_parent], &nums[new_parent]);
        
        // Perform recurrsion on new parent and adjust the children
        my_sort__max_heapify(nums, size, new_parent);
    }
}

static void my_sort__min_heapify(int32_t nums[], int32_t size, int32_t actual_parent) {
    int32_t new_parent = actual_parent;
    int32_t left_child, right_child;
    left_child = my_sort__get_left_child(new_parent);
    right_child = my_sort__get_right_child(new_parent);
    
    if ((left_child < size) && (nums[left_child] < nums[new_parent])) new_parent = left_child;
    
    if ((right_child < size) && (nums[right_child] < nums[new_parent])) new_parent = right_child;
    
    if (new_parent != actual_parent) {
        // Swap child with its parent if child is greater than parent
        my_sort__swap(&nums[actual_parent], &nums[new_parent]);
        
        // Perform recurrsion on new parent and adjust the children
        my_sort__min_heapify(nums, size, new_parent);
    }
}

static void my_sort__build_max_heap(int32_t nums[], int32_t size) {
    for (int32_t parent = (size / 2) - 1; parent >= 0; parent--)
        my_sort__max_heapify(nums, size, parent);
}

static void my_sort__build_min_heap(int32_t nums[], int32_t size) {
    for (int32_t parent = (size / 2) - 1; parent >= 0; parent--)
        my_sort__min_heapify(nums, size, parent);
}

static void my_sort__delete_root_elements_to_sort(int32_t nums[], int32_t size, heap_type__e type) {
    for (int32_t i = size-1; i >= 0; i--) {
        // Move root element at the end
        my_sort__swap(&nums[0], &nums[i]);
        
        // Rearrange the tree and perform heapify
        switch (type) {
            case HEAP_MAX:
                my_sort__max_heapify(nums, i, 0);
                break;
            case HEAP_MIN:
                my_sort__min_heapify(nums, i, 0);
                break;
            default:
                break;
        }
    }
}

void my_sort__heap_sort(int32_t nums[], int32_t size, heap_type__e type) {
    switch (type) {
        case HEAP_MAX:
            my_sort__build_max_heap(nums, size);
            my_sort__print_array(nums, size);
            break;
            
        case HEAP_MIN:
            my_sort__build_min_heap(nums, size);
            my_sort__print_array(nums, size);
            break;
            
        default:
            break;
    }
    my_sort__delete_root_elements_to_sort(nums, size, type);
}

/**
B U C K E T    S O R T
PERFORMACE:
Time Complexity: O(n)
Space Complexity: O(n)
*/
static const uint32_t BUCKETS = 10;
void my_sort__bucket_sort(int32_t nums[], int32_t size) {
    int32_t i = 0, j = 0;
    int32_t bucket[BUCKETS] = {0};
    for (j = 0; j < size; j++)
        ++bucket[nums[j]];
    for (j = 0; j < BUCKETS; j++)
        while (bucket[j]-- > 0) nums[i++] = j;
}
