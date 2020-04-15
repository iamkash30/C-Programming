//
//  my_list.h
//  cLinkedList
//
//  Created by Aakash Chitroda on 4/14/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_list_h
#define my_list_h

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>

struct _list__t {
    int32_t val;
    struct _list__t *next;
};
typedef struct _list__t list__t;

void my_list__print_list(list__t *list);

list__t *my_list__create_new_list_node(int32_t val);

list__t *my_list__insert_at_head(list__t *list, int32_t val);

list__t *my_list__insert_at_tail(list__t *list, int32_t val);

bool my_list__lookup_recurrsive(list__t *list, int32_t target);

bool my_list__lookup_iterative(list__t *list, int32_t target);
uint32_t my_list__get_length(list__t *list);

list__t *my_list__reverse(list__t *list);

list__t *my_list__add_two_list(list__t *list1, list__t *list2);

list__t *my_list__merge_two_list(list__t *list1, list__t *list2);
#endif /* my_list_h */
