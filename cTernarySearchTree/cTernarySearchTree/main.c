//
//  main.c
//  cTernarySearchTree
//
//  Created by Aakash Chitroda on 3/31/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_ternary_search_trees.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    TST_node *tst_ptr = NULL;
    uint8_t word[] = "boats";
    uint8_t word1[] = "boat";
    tst_ptr = my_tst__insert_recurrsive(tst_ptr, &word[0]);
    tst_ptr = my_tst__insert_recurrsive(tst_ptr, &word1[0]);
    uint8_t search_word[] = "boat";
    my_tst__search_iterative(tst_ptr, search_word) ? printf("Found\n") : printf("Not found\n");
    return 0;
}
