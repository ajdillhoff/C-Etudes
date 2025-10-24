#include "bt_utils.h"
#include <assert.h>

// Helper function to check if a tree is a valid BST
int is_valid_bst(BTNode *node, int min_val, int max_val) {
    if (node == NULL) {
        return 1;
    }
    
    if (node->data <= min_val || node->data >= max_val) {
        return 0;
    }
    
    return is_valid_bst(node->left, min_val, node->data) &&
           is_valid_bst(node->right, node->data, max_val);
}

// Helper function to get tree height
int get_height(BTNode *node) {
    if (node == NULL) {
        return 0;
    }
    
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    
    return 1 + (left_height > right_height ? left_height : right_height);
}

// Helper function to check if tree is balanced
int is_balanced(BTNode *node) {
    if (node == NULL) {
        return 1;
    }
    
    int left_height = get_height(node->left);
    int right_height = get_height(node->right);
    
    int height_diff = left_height - right_height;
    if (height_diff < 0) height_diff = -height_diff;
    
    return height_diff <= 1 && is_balanced(node->left) && is_balanced(node->right);
}

// Test case 1: Small array with odd number of elements
void test_small_odd_array() {
    printf("Testing small odd array...\n");
    int data[] = {3, 7, 4, 1, 5, 2, 9};
    int n = 7;
    
    BTNode *root = build_balanced_bst(data, n);
    
    // Verify it's a valid BST
    assert(is_valid_bst(root, -2147483648, 2147483647));
    
    // Verify it's balanced
    assert(is_balanced(root));
    
    // Verify all elements are present
    assert(search(root, 1) != NULL);
    assert(search(root, 3) != NULL);
    assert(search(root, 4) != NULL);
    assert(search(root, 5) != NULL);
    
    release_tree(root);
    printf("Small odd array test passed!\n");
}

// Test case 2: Array with even number of elements
void test_even_array() {
    printf("Testing even array...\n");
    int data[] = {10, 5, 15, 3, 7, 12};
    int n = 6;
    
    BTNode *root = build_balanced_bst(data, n);
    
    // Verify it's a valid BST
    assert(is_valid_bst(root, -2147483648, 2147483647));
    
    // Verify it's balanced
    assert(is_balanced(root));
    
    // Verify all elements are present
    assert(search(root, 3) != NULL);
    assert(search(root, 5) != NULL);
    assert(search(root, 7) != NULL);
    assert(search(root, 10) != NULL);
    assert(search(root, 12) != NULL);
    assert(search(root, 15) != NULL);
    
    release_tree(root);
    printf("Even array test passed!\n");
}

int main() {
    printf("Running balanced BST tests...\n\n");
    
    test_small_odd_array();
    test_even_array();
    
    printf("\nAll tests passed!\n");
    return 0;
}