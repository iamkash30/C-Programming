//
//  my_trie.h
//  cTries
//
//  Created by Aakash Chitroda on 3/29/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_trie_h
#define my_trie_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

#define ASCII_TABLE_SIZE  128

typedef struct _trie_s {
    bool is_end_of_word;
    struct _trie_s *child[ASCII_TABLE_SIZE];
} trie_s;

trie_s *my_trie__initialize(void);

void my_trie__insert(trie_s *trie_ptr_obj, uint8_t *word);

bool my_trie__search(trie_s *trie_ptr_obj, uint8_t *word);

bool my_trie__search_with_prefix(trie_s *trie_ptr_obj, uint8_t *word);

void my_trie__print_trie(trie_s *trie_ptr_obj, uint8_t str[], int str_index);

bool my_trie__is_end_of_word(trie_s *trie_ptr_obj);

void my_trie__destroy(trie_s *trie_ptr_obj);

#endif /* my_trie_h */
