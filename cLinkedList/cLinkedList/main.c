//
//  main.c
//  cLinkedList
//
//  Created by Aakash Chitroda on 4/14/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_list.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    list__t *list = NULL;
    list = my_list__create_new_list_node(1);
    list = my_list__insert_at_head(list, 2);
    list = my_list__insert_at_head(list, 3);
    my_list__print_list(list);
    my_list__lookup_iterative(list, 0) ? printf("True\n") : printf("False\n");
    my_list__print_list(list);
    list = my_list__reverse(list);
    my_list__print_list(list);
    
    list__t *list1 = NULL, *list2 = NULL;
    list1 = my_list__create_new_list_node(5);
    list1 = my_list__insert_at_tail(list1, 5);
    list1 = my_list__insert_at_tail(list1, 5);
    
    list2 = my_list__create_new_list_node(5);
    list2 = my_list__insert_at_tail(list2, 5);
    list2 = my_list__insert_at_tail(list2, 5);
    
    list__t *result = NULL;
    result = my_list__add_two_list(list1, list2);
    my_list__print_list(result);
    return 0;
}
    
