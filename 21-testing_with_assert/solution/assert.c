#include <assert.h>
#include <stdio.h>

#include "bt_utils.h"

int main() {

    BTNode *root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 10);

    printf("Insert tests\n");

    assert(root->data == 5);
    assert(root->left->data == 3);
    assert(root->right->data == 10);

    printf("Success!\n");

    printf("Search tests\n");

    BTNode *result = search(root, 5);

    assert(result == root);

    result = search(root, 3);

    assert(result == root->left);

    result = search(root, 10);

    assert(result == root->right);

    printf("Success!\n");

    return 0;
}