//
//  my_memory_manager.c
//  cMemoryManager
//
//  Created by Aakash Chitroda on 4/8/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_memory_manager.h"
#include <pthread.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>

typedef char ALIGN[16];

union header {
    struct {
        size_t size;
        unsigned is_mem_free;
        union header *next;
    }s;
    /* force the header to be aligned to 16 bytes */
    ALIGN stub;
};
typedef union header header_t;

static header_t *head, *tail;

static header_t *get_free_block(size_t size) {
    header_t *curr = head;
    while (curr) {
        /* see if there's a free block that can accomodate requested size */
        if ((1 == curr->s.is_mem_free) && (curr->s.size >= size)) {
            return curr;
        }
        curr = curr->s.next;
    }
    return NULL;
}

void *my_mem__malloc(size_t size) {
    if (!size) return NULL;
    size_t total_size = 0;
    header_t *header = NULL;
    void *block = NULL;
    header = get_free_block(size);
    if (header != NULL) {
        header->s.is_mem_free = 0;
        return (void *)(header + 1);
    }
    total_size = sizeof(header_t) + size;
    block = sbrk(total_size);
    if ((void *)-1 == block) {
        return NULL;
    }
    header = block;
    header->s.is_mem_free = 0;
    header->s.size = size;
    header->s.next = NULL;
    if (!head) head = header;
    if (tail) tail->s.next = header;
    tail = header;
    return (void *)(header + 1);
}

void *my_mam__calloc(size_t num_of_blocks, size_t size_of_each_block) {
    if (!num_of_blocks || !size_of_each_block) return NULL;
    void *block;
    header_t *header;
    size_t size = num_of_blocks * size_of_each_block;
    // Check multiplication overflow
    if (size_of_each_block != size / num_of_blocks) return NULL;
    return NULL;
}

void my_mem__free(void *block) {
    if (!block) return;
    void *program_break;
    header_t *header, *temp;
    
    /* sbrk(0) gives the current program break address */
    program_break = sbrk(0);
    
    // Go to previous address where the block header is stored
    header = (header_t *)block - 1;
    
    // If current block is the end block, then delete it from memory
    if ((char *)block + header->s.size == program_break) {
        if (head == tail) head = tail = NULL;
        else {
            temp = head;
            while (temp) {
                if (temp->s.next == tail) {
                    temp->s.next = NULL;
                    tail = temp;
                }
                temp = temp->s.next;
            }
        }
        sbrk(0 - sizeof(header_t) - header->s.size);
        return;
    }
    header->s.is_mem_free = 1;
    return;
}

/* A debug function to print the entire link list */
void print_mem_list(void)
{
    header_t *curr = head;
    printf("head = %p, tail = %p \n", (void*)head, (void*)tail);
    while(curr) {
        printf("addr = %p, size = %zu, is_mem_free=%u, next=%p\n",
            (void*)curr, curr->s.size, curr->s.is_mem_free, (void*)curr->s.next);
        curr = curr->s.next;
    }
}
