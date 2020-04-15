//
//  my_list.c
//  cLinkedList
//
//  Created by Aakash Chitroda on 4/14/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_list.h"

void my_list__print_list(list__t *list) {
    list__t *curr = list;
    printf("\n Start of Printing \n");
    while (curr) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("NULL\n End of Printing \n");
}

list__t *my_list__create_new_list_node(int32_t val) {
    list__t *new_list = (list__t *)malloc(sizeof(list__t));
    if (!new_list) return NULL;
    new_list->val = val;
    new_list->next = NULL;
    return new_list;
}

list__t *my_list__insert_at_head(list__t *list, int32_t val) {
    list__t *curr = list;
    list__t *new_list = my_list__create_new_list_node(val);
    if (!curr) {
        curr = new_list;
    } else {
        new_list->next = curr;
        list = new_list;
    }
    return list;
}

list__t *my_list__insert_at_tail(list__t *list, int32_t val) {
    list__t *new_list = my_list__create_new_list_node(val);
    if (!list) {
        list = new_list;
    } else {
        list__t *curr = list;
        while (curr->next) curr = curr->next;
        curr->next = new_list;
    }
    return list;
}

bool my_list__lookup_recurrsive(list__t *list, int32_t target) {
    if (NULL == list) return false;
    else if (list->val == target) return true;
    else return my_list__lookup_recurrsive(list->next, target);
}

bool my_list__lookup_iterative(list__t *list, int32_t target) {
    bool found = false;
    while (list) {
        if (list->val == target) {
            found = true;
        }
        list = list->next;
    }
    return found;
}

uint32_t my_list__get_length(list__t *list) {
    list__t *curr = list;
    uint32_t length = 0;
    
    while (NULL != curr) {
        length++;
        curr = curr->next;
    }
    return length;
}

list__t *my_list__reverse(list__t *list) {
    list__t *prev, *curr, *next;
    prev = NULL;
    curr = list;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list = prev;
    return prev;
}

list__t *my_list__add_two_list(list__t *list1, list__t *list2) {
    if (NULL == list1 && NULL == list2) return NULL;
    else if(NULL == list2) return list1;
    else if (NULL == list1) return list2;
    list1 = my_list__reverse(list1);
    list2 = my_list__reverse(list2);
    int32_t carry = 0, sum = 0;
    list__t *result = NULL;
    
    while (list1 != NULL || list2 != NULL) {
        sum = carry + ((list1) ? list1->val : 0) + ((list2) ? list2->val : 0);
        
        carry = (sum >= 10) ? 1 : 0;
        
        // If sume is 11 then we have carry as 1, we need sum to be 1;
        sum = sum % 10;
        
        result = my_list__insert_at_tail(result, sum);
        
        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }
    if (carry > 0) {
        result = my_list__insert_at_tail(result, carry);
    }
    result = my_list__reverse(result);
    return result;
}

list__t *my_list__merge_two_list(list__t *list1, list__t *list2) {
    return NULL;
}
