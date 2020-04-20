//
//  main.c
//  cBinaryTree
//
//  Created by Aakash Chitroda on 3/28/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include <stdio.h>
#include "my_tree.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    TreeNode *node = NULL;
    node = my_tree__create_new_treeNode(5);
    node = my_tree__insert_treeNode(node, 3);
    node = my_tree__insert_treeNode(node, 7);
    node = my_tree__insert_treeNode(node, 2);
    node = my_tree__insert_treeNode(node, 4);
    node = my_tree__insert_treeNode(node, 6);
    node = my_tree__insert_treeNode(node, 8);
    
    
    my_tree__print_preorder_recurrsive(node);
    my_tree__print_preorder_iterative(node);
    my_tree__print_inorder_recurrsive(node);
    my_tree__print_inorder_iterative(node);
    my_tree__print_postorder_recurrsive(node);
    my_tree__print_postorder_iterative(node);
    
    return 0;
}
