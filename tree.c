#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct binarytree{
    int item;
    struct binarytree *left;
    struct binarytree *right;
};
typedef struct binarytree btree;

void create_empty_binarytree(btree **root){
    *root = NULL;
}

btree *create_newnode(int item){
    btree *new_node = (btree*) malloc(sizeof(btree));
    new_node->item = item;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

btree *add_node_bt(btree *root, int item){
    if (root == NULL) root = create_newnode(item);
    else if (root->item > item) root->left = add_node_bt(root->left, item);
    else root->right = add_node_bt(root->right, item);
    return root;
}

void print_inorder(btree *node){
    if (node != NULL){
        print_inorder(node->left);
        printf("%d ", node->item);
        print_inorder(node->right);
    }
}

int b_search(btree *node, int item, int comparisons){
    if (node == NULL) return 0;
    else if (node->item == item) return comparisons;
    else if (node->item > item) return b_search(node->left, item, comparisons+1);
    else return b_search(node->right, item, comparisons+1);
}

