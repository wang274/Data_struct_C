#ifndef __AVL_H__
#define __AVL_H__
typedef struct avl_node{
    int key;
    struct avl_node *left;
    struct avl_node *right;
    int height;
}avl_node;

typedef struct avl{
    struct avl_node *root;
    int size;
}avl;


#endif