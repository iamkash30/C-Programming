//
//  my_ternary_search_trees.h
//  cTernarySearchTree
//
//  Created by Aakash Chitroda on 3/31/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_ternary_search_trees_h
#define my_ternary_search_trees_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct _TST_node {
    uint8_t data;
    bool is_end_of_string;
    struct _TST_node *left;
    struct _TST_node *equal;
    struct _TST_node *right;
} TST_node;

TST_node *my_tst__insert_recurrsive(TST_node *tst_node_ptr, uint8_t *word);

bool my_tst__search_recurrsive(TST_node *tst_node_ptr, uint8_t *word);

bool my_tst__search_iterative(TST_node *tst_node_ptr, uint8_t *word);

#endif /* my_ternary_search_trees_h */
