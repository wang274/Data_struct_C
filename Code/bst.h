#ifndef __BST_H__
#define __BST_H__

typedef struct bst_node{
    int key;
    struct bst_node *left;
    struct bst_node *right;
}bst_node;

typedef struct bst{
    struct bst_node *root;
    int size;
}bst;

bst* bst_create();
bst_node *bst_create_node(int key);
bst_node *bst_search_zmy(bst_node* node, int key);
bst_node* bst_search(bst_node *node, int type, int key);
bst* bst_insert(bst *bst, int key);
bst_node *bst_find_max_node(bst_node *node, int type);
void bst_delete(bst *bst, int key);
void bst_in_tra(bst_node *node);
void bst_delete2(bst *bst, int key);


#endif