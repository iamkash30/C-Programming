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

struct _TreeNode {
    int32_t val;
    struct _TreeNode *left;
    struct _TreeNode *right;
};

typedef struct _Treenode TreeNode;

TreeNode *my_tree__create_new_treeNode(int val);
TreeNode *my_tree__insert_treeNode(TreeNode *node, int val);
#endif /* my_tree_h */
