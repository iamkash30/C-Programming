//
//  main.c
//  cTries
//
//  Created by Aakash Chitroda on 3/29/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_trie.h"
#include "string.h"

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, Trie!\n");
    uint8_t words[][9] = {
        "high", "higher", "highest",
        "low", "lower", "lowest",
        "an", "answer", "any",
    };
    
    trie_s *trie_ptr = NULL;
    trie_ptr = my_trie__initialize();
    for (int32_t i = 0; i < ARRAY_SIZE(words); i++)
        my_trie__insert(trie_ptr, words[i]);
    uint8_t str[100] = {'\0'};
    my_trie__print_trie(trie_ptr, str, 0);
    
    my_trie__search(trie_ptr, (uint8_t *)("answer")) ? printf("Found\n") : printf("Not found\n");
    
    my_trie__search(trie_ptr, (uint8_t *)("ans")) ? printf("Found\n") : printf("Not found\n");
    
    my_trie__search_with_prefix(trie_ptr, (uint8_t *)("ans")) ? printf("Prefix Found\n") : printf("Prefix Not found\n");
    return 0;
}
