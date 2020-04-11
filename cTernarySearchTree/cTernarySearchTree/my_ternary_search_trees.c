//
//  my_ternary_search_trees.c
//  cTernarySearchTree
//
//  Created by Aakash Chitroda on 3/31/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_ternary_search_trees.h"

static TST_node *my_tst__initialize(uint8_t character) {
    TST_node *new_tst_node = NULL;
    new_tst_node = (TST_node *)malloc(sizeof(TST_node));
    if (NULL != new_tst_node) {
        new_tst_node->data = character;
        new_tst_node->is_end_of_string = false;
        new_tst_node->left = NULL;
        new_tst_node->equal = NULL;
        new_tst_node->right = NULL;
    }
    return new_tst_node;
}

TST_node *my_tst__insert_recurrsive(TST_node *tst_node_ptr, uint8_t *word) {
    if (NULL == tst_node_ptr) {
        tst_node_ptr = my_tst__initialize(*word);
    }
    if (*word < tst_node_ptr->data) {
        tst_node_ptr->left = my_tst__insert_recurrsive(tst_node_ptr->left, word);
    } else if (*word > tst_node_ptr->data) {
        tst_node_ptr->right = my_tst__insert_recurrsive(tst_node_ptr->right, word);
    } else {
        if (*(word + 1)) {
            tst_node_ptr->equal = my_tst__insert_recurrsive(tst_node_ptr->equal, word + 1);
        } else {
            tst_node_ptr->is_end_of_string = true;
        }
    }
    return tst_node_ptr;
}

bool my_tst__search_recurrsive(TST_node *tst_node_ptr, uint8_t *word) {
    if (NULL == tst_node_ptr) return false;
    else if (*word < tst_node_ptr->data) return my_tst__search_recurrsive(tst_node_ptr->left, word);
    else if (*word > tst_node_ptr->data) return my_tst__search_recurrsive(tst_node_ptr->right, word);
    else {
        if (tst_node_ptr->is_end_of_string && *(word+1) == '\0')
            return true;
        else return my_tst__search_recurrsive(tst_node_ptr->equal, ++word);
    }
}

bool my_tst__search_iterative(TST_node *tst_node_ptr, uint8_t *word) {
    while (*word && tst_node_ptr != NULL) {
        if (*word < tst_node_ptr->data) tst_node_ptr = tst_node_ptr->left;
        else if (*word > tst_node_ptr->data) tst_node_ptr = tst_node_ptr->right;
        else {
            if ((true == tst_node_ptr->is_end_of_string) && ('\0' == *(word + 1)))
                return true;
            tst_node_ptr = tst_node_ptr->equal;
        }
        word++;
    }
    return false;
}
