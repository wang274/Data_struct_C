#ifndef __Tree_H__
#define __Tree_H__

typedef struct tree_node{
    struct tree_node* left;
    struct tree_node *right;
    char key;
}tree_node;


void in_tra2(tree_node* node);
void pos_tra(tree_node *node);
void level_tra(tree_node *root);
void pre_tra2(tree_node *node);
void pos_tra(tree_node *node);
void in_tra(tree_node *node);
void pre_tra(tree_node *node);
tree_node *tree_create();
tree_node *tree_create_node(char key);
#endif