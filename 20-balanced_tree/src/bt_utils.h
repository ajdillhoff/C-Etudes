#ifndef BT_UTILS_H
#define BT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BTNode BTNode;
struct BTNode {
    int data;
    BTNode *left;
    BTNode *right;
};

BTNode *add_btnode(int);
void inorder_dfs(BTNode *);
void insert(BTNode **, int);
BTNode *search(BTNode *, int);
void release_tree(BTNode *);
BTNode *build_balanced_bst(int *, int);

#endif  // BT_UTILS_H
