//
//  my_memory_manager.h
//  cMemoryManager
//
//  Created by Aakash Chitroda on 4/8/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_memory_manager_h
#define my_memory_manager_h

#include <stdio.h>

void *my_mem__malloc(size_t size);

void *my_mam__calloc(size_t num_of_blocks, size_t size_of_each_block);

void my_mem__free(void *block);

void print_mem_list(void);

#endif /* my_memory_manager_h */
