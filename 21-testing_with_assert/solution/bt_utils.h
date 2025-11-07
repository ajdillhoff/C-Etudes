#ifndef BT_UTILS_H
#define BT_UTILS_H

#include <stdio.h>
#include <stdlib.h>

struct BTNode {
    int data;
    struct BTNode *p;
    struct BTNode *left;
    struct BTNode *right;
};
typedef struct BTNode BTNode;

typedef struct Node Node;
struct Node {
    void *data;
    Node *next;
};

typedef enum {
    PREORDER,
    INORDER,
    POSTORDER
} traverse_type;

BTNode *add_btnode(int);
void enqueue(Node **, void *);
Node *dequeue(Node **);
void bfs(BTNode *);
void dfs(BTNode *, traverse_type);
void insert(BTNode **, int);
BTNode *minimum(BTNode *);
BTNode *successor(BTNode *);
BTNode *search(BTNode *, int);
void release_tree(BTNode *);

#endif  // BT_UTILS_H
