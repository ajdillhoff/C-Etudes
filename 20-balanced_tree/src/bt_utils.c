#include "bt_utils.h"

BTNode *add_btnode(int data) {
    BTNode *node = calloc(1, sizeof(BTNode));
    node->data = data;

    return node;
}

void inorder_dfs(BTNode *root) {
    if (root == NULL) {
        return;
    }

    inorder_dfs(root->left);

    printf("%d\n", root->data);

    inorder_dfs(root->right);
}

void insert(BTNode **root, int val) {
    BTNode **temp = root;
    while (*temp != NULL) {
        if (val >= (*temp)->data) {
            temp = &(*temp)->right;
        } else {
            temp = &(*temp)->left;
        }
    }

    *temp = add_btnode(val);
}

BTNode *search(BTNode *node, int val) {
    if (node == NULL || val == node->data) {
        return node;
    } else if (val > node->data) {
        return search(node->right, val);
    } else {
        return search(node->left, val);
    }
}

void release_tree(BTNode *node) {
    if (node != NULL) {
        release_tree(node->left);
        release_tree(node->right);
        free(node);
    }
}

/*
 * Builds a balanced Binary Search Tree given a list of unsorted integers.
 * 
 * Arguments:
 *   data: An array of integers.
 *   n: The number of integers in the array.
 * 
 * Returns:
 *   A pointer to the root node of the balanced BST.
 */
BTNode *build_balanced_bst(int *data, int n) {
    // TODO: Implement this function to build a balanced BST.
    return NULL;
}
