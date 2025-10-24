# Building a Balanced Binary Search Tree

In this exercise, you will implement a function to build a balanced binary search tree (BST) from a list of unsorted integers. A balanced BST is a binary tree in which the depth of the two subtrees of every node never differs by more than one. The trick to completing this exercise is to understand the structure of a balanced search tree. Given a BST, the root is the median value of the sorted list of values. The left subtree contains all values less than the root, and the right subtree contains all values greater than the root. This property holds recursively for each subtree.

Given this understanding, you should use `qsort` to sort the input list. Finding the median is trivial once it is sorted. You can then recursively build the left and right subtrees using the same approach.

## Instructions

Using the provided tree operations, complete the function `build_balanced_bst` in `tree_utils.c` to construct a balanced binary search tree from an unsorted list of integers. If you are successful, the provided tests in `test_balanced_tree.c` will pass. To compile and run the tests, use the following commands:

```bash
gcc test_balanced_tree.c tree_utils.c -o test_balanced_tree
./test_balanced_tree
```