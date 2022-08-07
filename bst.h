#pragma once

typedef struct bstNode {
    int data_item;
    struct bstNode *left;
    struct bstNode *right;
} *BSTNodePtr;

typedef struct bst {
    BSTNodePtr root;
} BST;

BST new_bst();

BSTNodePtr find_bst(BST *self, int n);

void insert_bst(BST *self, int n);

void delete_bst(BST *self, int n);

void print_pre_order_bst(BST *self);

void print_in_order_bst(BST *self);

void print_post_order_bst(BST *self);

int bst_height(BST *self);

