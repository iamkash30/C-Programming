//
//  my_trie.c
//  cTries
//
//  Created by Aakash Chitroda on 3/29/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_trie.h"

trie_s *my_trie__initialize(void) {
    trie_s *newTrie = (trie_s *)malloc(sizeof(trie_s));
    if (NULL != newTrie) {
        newTrie->is_end_of_word = false;
        for (int32_t i = 0; i < ASCII_TABLE_SIZE; ++i)
            newTrie->child[i] = NULL;
    }
    return newTrie;
}

void my_trie__insert(trie_s *trie_ptr_obj, uint8_t *word) {
    if (NULL == trie_ptr_obj) {
        fprintf(stderr, "Error: Trie object is not initialized\n");
        return;
    }
    trie_s *local_trie_ptr = trie_ptr_obj;
    while (*word) {
        // If character doesn't exist in trie, create it
        if (NULL == local_trie_ptr->child[*word - '\0']) {
            local_trie_ptr->child[*word - '\0'] = my_trie__initialize();
        }
        
        // Move to next character in the path
        local_trie_ptr = local_trie_ptr->child[*word - '\0'];
        
        // Move to next character of the word
        word++;
    }
    local_trie_ptr->is_end_of_word = true;
    return;
}

bool my_trie__search(trie_s *trie_ptr_obj, uint8_t *word) {
    if (NULL == trie_ptr_obj) {
        fprintf(stderr, "Error: Trie is empty or is not initialized\n");
        return false;
    }
    trie_s *local_trie_ptr = trie_ptr_obj;
    
    while (*word) {
        local_trie_ptr = local_trie_ptr->child[*word - '\0'];
        if (NULL == local_trie_ptr) return false;
        else word++;
    }
    return local_trie_ptr->is_end_of_word;
}

bool my_trie__search_with_prefix(trie_s *trie_ptr_obj, uint8_t *word) {
    if (NULL == trie_ptr_obj) {
        fprintf(stderr, "Error: Trie object is not initialized!\n");
        return false;
    }
    trie_s *local_trie_ptr = trie_ptr_obj;
    bool search_result = true;
    while (*word) {
        local_trie_ptr = local_trie_ptr->child[*word - '\0'];
        if (NULL == local_trie_ptr) {
            search_result = false;
            break;
        }
        word++;
    }
    return search_result;
}

void my_trie__print_trie(trie_s *trie_ptr_obj, uint8_t str[], int str_index) {
    if (true == my_trie__is_end_of_word(trie_ptr_obj)) {
        str[str_index] = '\0';
        printf("%s\n", str);
    }
    
    for (int32_t i = 0; i < ASCII_TABLE_SIZE; ++i) {
        if (trie_ptr_obj->child[i] != NULL) {
            str[str_index] = i + '\0';
            my_trie__print_trie(trie_ptr_obj->child[i], str, str_index + 1);
        }
    }
}

bool my_trie__is_end_of_word(trie_s *trie_ptr_obj) {
    return trie_ptr_obj->is_end_of_word;
}

void my_trie__destroy(trie_s *trie_ptr_obj) {
    if (NULL != trie_ptr_obj) {
        free(trie_ptr_obj);
        trie_ptr_obj = NULL;
    }
    return;
}
