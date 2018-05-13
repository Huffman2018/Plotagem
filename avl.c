#include <stdio.h>
#include <stdlib.h>

struct _bt {
	int item;
	int h;
	struct _bt *left;
	struct _bt *right;
}; 
typedef struct _bt avl_tree;

void create_empty_avl_tree(avl_tree **root) {
	*root = NULL;
}

avl_tree* create_avl_tree(int item, avl_tree *left, avl_tree *right) {
	avl_tree *bt = (avl_tree*) malloc(sizeof(avl_tree));
	bt->item = item;
	bt->h = 0;
	bt->left = left;
	bt->right = right;
	return bt;
}

int max(int a, int b) {
	if (a > b)	return a;
	else 		return b;
}

int height(avl_tree *bt) {
	if (bt == NULL)	return -1;
	else			return 1 + max( height(bt->left), height(bt->right) );
}

int is_balanced(avl_tree *bt) {
	int bf = height(bt->left) - height(bt->right);
	return ( (bf >= -1) && (bf <= 1) );
}

int balance_factor(avl_tree *bt) {
	if (bt == NULL)
		return 0;
	else if ((bt->left != NULL) && (bt->right != NULL))
		return (bt->left->h - bt->right->h);
	else if ((bt->left != NULL) && (bt->right == NULL))
		return (1 + bt->left->h);
	else
		return (-bt->right->h - 1);
}

avl_tree* rotate_left(avl_tree *bt) {
	avl_tree *subtree_root = NULL;
	if (bt != NULL && bt->right != NULL) {
		subtree_root = bt->right;
		bt->right = subtree_root->left;
		subtree_root->left = bt;
	}
	subtree_root->h = height(subtree_root);
	bt->h = height(bt);
	return subtree_root;
}

avl_tree* rotate_right(avl_tree *bt) {
	avl_tree *subtree_root = NULL;
	if (bt != NULL && bt->left != NULL) {
		subtree_root = bt->left;
		bt->left = subtree_root->right;
		subtree_root->right = bt;
	}
	subtree_root->h = height(subtree_root);
	bt->h = height(bt);
	return subtree_root;
}

avl_tree* add_node_avl(avl_tree *bt, int item) {

	if (bt == NULL)
		return create_avl_tree(item, NULL, NULL);
	else if (bt->item > item)
		bt->left = add_node_avl(bt->left, item);
	else 
		bt->right = add_node_avl(bt->right, item);
	
	bt->h = height(bt);
	avl_tree *child;

	if (balance_factor(bt) == 2 || balance_factor(bt) == -2) {
		if (balance_factor(bt) == 2) {
			child = bt->left;
			if (balance_factor(child) == -1) {
				bt->left = rotate_left(child);
			}
			bt = rotate_right(bt);
		}
		else if (balance_factor(bt) == -2) {
			child = bt->right;
			if (balance_factor(child) == 1) {
				bt->right = rotate_right(child);
			}
			bt = rotate_left(bt);
		}
	}
	return bt;
}

void print_inorder_avl(avl_tree *bt) {
	if (bt != NULL) {
		print_inorder_avl(bt->left);
		printf("%d ", bt->item);
		print_inorder_avl(bt->right);
	}
}

void print_preorder_avl(avl_tree *bt) {
	if (bt != NULL) {
		printf("%d ", bt->item);
		print_preorder_avl(bt->left);
		print_preorder_avl(bt->right);
	}
}

void print_postorder_avl(avl_tree *bt) {
	if (bt != NULL) {
		print_postorder_avl(bt->left);
		print_postorder_avl(bt->right);
		printf("%d ", bt->item);
	}
}


int avlsearch(avl_tree *node, int item, int comparisons){
    if (node == NULL) return 0;
    else if (node->item == item) return comparisons;
    else if (node->item > item) return avlsearch(node->left, item, comparisons+1);
    else return avlsearch(node->right, item, comparisons+1);
}
