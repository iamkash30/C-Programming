//
//  my_tree.h
//  cBinaryTree
//
//  Created by Aakash Chitroda on 3/28/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#ifndef my_tree_h
#define my_tree_h

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct _TreeNode {
    int32_t val;
    struct _TreeNode *left;
    struct _TreeNode *right;
} TreeNode;

TreeNode *my_tree__create_new_treeNode(int32_t val);

TreeNode *my_tree__insert_treeNode(TreeNode *node, int32_t val);

bool my_tree__lookup(TreeNode *node, int32_t target);

int32_t my_tree__get_size(TreeNode *node);

int32_t my_tree__get_max_depth(TreeNode *node);

int32_t my_tree__get_min_value_recurrsive(TreeNode *node);

int32_t my_tree__get_max_value_recurrsive(TreeNode *node);

int32_t my_tree__get_min_value_iterative(TreeNode *node);

int32_t my_tree__get_max_value_iterative(TreeNode *node);

void my_tree__print_preorder_recurrsive(TreeNode *node);

void my_tree__print_preorder_iterative(TreeNode *node);

void my_tree__print_inorder_recurrsive(TreeNode *node);

void my_tree__print_inorder_iterative(TreeNode *node);

void my_tree__print_postorder_recurrsive(TreeNode *node);

void my_tree__print_postorder_iterative(TreeNode *node);

void my_tree__print_level_order(TreeNode *node);

bool my_tree__is_bst_not_efficient(TreeNode *node);

bool my_tree__is_bst_efficient(TreeNode *node);

TreeNode *my_tree__delete_node(TreeNode *node, int target);

TreeNode *my_tree__get_inorder_successor(TreeNode *node, int32_t successor_of_this_value);

bool my_tree__has_path_sum(TreeNode *node, int sum);

#endif /* my_tree_h */
