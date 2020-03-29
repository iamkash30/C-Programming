//
//  my_tree.c
//  cBinaryTree
//
//  Created by Aakash Chitroda on 3/28/20.
//  Copyright © 2020 Aakash Chitroda. All rights reserved.
//

#include "my_tree.h"
#include "my_queue.h"

TreeNode *my_tree__create_new_treeNode(int32_t val) {
    TreeNode *newTreeNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newTreeNode != NULL) {
        newTreeNode->val = val;
        newTreeNode->left = newTreeNode->right = NULL;
    }
    return newTreeNode;
}

TreeNode *my_tree__insert_treeNode(TreeNode *node, int32_t val) {
    // Base case: If tree is empty
    if (NULL == node) {
        TreeNode *newTreeNode = my_tree__create_new_treeNode(val);
        return newTreeNode;
    } else if (val <= node->val) {
        node->left = my_tree__insert_treeNode(node->left, val);
    } else {
        node->right = my_tree__insert_treeNode(node->right, val);
    }
    
    // Return the unchanged root pointer
    return node;
}

bool my_tree__lookup(TreeNode *node, int32_t target) {
    // Base case: If node is NULL
    if (NULL == node) return false;
    else if (target < node->val) return my_tree__lookup(node->left, target);
    else if (target > node->val) return my_tree__lookup(node->right, target);
    else return true;
}

int32_t my_tree__get_size(TreeNode *node) {
    if (NULL == node) return 0;
    else
        return (my_tree__get_size(node->left) + 1 + my_tree__get_size(node->right));
}

// Do the stack trace using online python tool.. Google it
int32_t my_tree__get_max_depth(TreeNode *node) {
    if (NULL == node) return 0;
    int depth_at_left = my_tree__get_max_depth(node->left);
    int depth_at_right = my_tree__get_max_depth(node->right);
    if (depth_at_left > depth_at_right)
        return depth_at_left + 1;
    else return depth_at_right + 1;
}

int32_t my_tree__get_min_value_recurrsive(TreeNode *node) {
    if (NULL == node) return -1;
    else if (NULL == node->left) return node->val;
    else return my_tree__get_min_value_recurrsive(node->left);
}

int32_t my_tree__get_max_value_recurrsive(TreeNode *node) {
    if (NULL == node) return -1;
    else if (NULL == node->right) return node->val;
    else return my_tree__get_max_value_recurrsive(node->right);
}

int32_t my_tree__get_min_value_iterative(TreeNode *node) {
    if (NULL == node) return -1;
    TreeNode *localNode = node;
    
    while (localNode->left != NULL) {
        localNode = localNode ->left;
    }
    return localNode->val;
}

int32_t my_tree__get_max_value_iterative(TreeNode *node) {
    if (NULL == node) return -1;
    TreeNode *localNode = node;
    
    while (localNode->right != NULL) {
        localNode = localNode ->right;
    }
    return localNode->val;
}

/*
 DLR
 1. D - Visit the node
 2. L - Go left
 3. R - Go right
*/
void my_tree__print_preorder_recurrsive(TreeNode *node) {
    if (NULL == node) return;
    printf("%d ", node->val);
    my_tree__print_preorder_recurrsive(node->left);
    my_tree__print_preorder_recurrsive(node->right);
}

/*
 LDR
 1. L - Go left
 2. D - Visit the node
 3. R - Go right
*/
void my_tree__print_inorder_recurrsive(TreeNode *node) {
    if (NULL == node) return;
    my_tree__print_preorder_recurrsive(node->left);
    printf("%d ", node->val);
    my_tree__print_preorder_recurrsive(node->right);
}

/*
 LRD
 1. L - Go left
 2. R - Go right
 3. D - Visit the node
*/
void my_tree__print_postorder_recurrsive(TreeNode *node) {
    my_tree__print_preorder_recurrsive(node->left);
    my_tree__print_preorder_recurrsive(node->right);
    printf("%d ", node->val);
}

/*
 Also,called as Breadth-First Search (BFS)
 This can be solved using Queue.
 In C++, there is STL called Queue that can be used.
 But, in C, we need to implement Queue for TreeNode
 */
void my_tree__print_level_order(TreeNode *node) {
    queue *q = NULL;
    q = my_queue__create();
    my_queue__push(q, node);
    TreeNode *curr = NULL;
    
    while (my_queue__empty(q) != true) {
        curr = my_queue__top(q);
        printf("%d ", curr->val);
        if (curr->left != NULL) my_queue__push(q, curr->left);
        if (curr->right != NULL) my_queue__push(q, curr->right);
        my_queue__pop(q);
    }
    printf("\n");
    return;
}

bool my_tree__is_bst_not_efficient(TreeNode *node) {
    if (NULL == node) return true;
    else if (node->val < my_tree__get_min_value_iterative(node->left) && (NULL != node->left)) return false;
    else if (node->val >= my_tree__get_max_value_iterative(node->right) && (NULL != node->right)) return false;
    
    if (my_tree__is_bst_not_efficient(node->left) != true || my_tree__is_bst_not_efficient(node->right) != true)
        return false;
    else
        return true;
}

static bool my_tree__is_bst_helper_function(TreeNode *node, int min_range, int max_range) {
    if (NULL == node) return true;
    else if ((node->val > min_range)
             && (node->val < max_range)
             && my_tree__is_bst_helper_function(node->left, min_range, node->val)
             && my_tree__is_bst_helper_function(node->right, node->val, max_range))
        return true;
    else return false;
}

bool my_tree__is_bst_efficient(TreeNode *node) {
    return my_tree__is_bst_helper_function(node, INT32_MIN, INT32_MAX);
}
