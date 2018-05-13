#include <stdio.h>
#include <stdlib.h>

typedef struct _bt avl_tree;

void create_empty_avl_tree(avl_tree **root);

avl_tree* create_avl_tree(int item, avl_tree *left, avl_tree *right);
int max(int a, int b);

int height(avl_tree *bt);

int is_balanced(avl_tree *bt);

int balance_factor(avl_tree *bt);

avl_tree* rotate_left(avl_tree *bt);

avl_tree* rotate_right(avl_tree *bt);

avl_tree* add_node_avl(avl_tree *bt, int item);

void print_inorder_avl(avl_tree *bt);

void print_preorder_avl(avl_tree *bt);

void print_postorder_avl(avl_tree *bt);

int avlsearch(avl_tree *node, int item, int comparisons);
