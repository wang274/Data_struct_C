#include <stdio.h>
#include "avl.h"
#include <stdlib.h>

avl_node* avl_create_node(int key){
    avl_node *node = (struct avl_node*)malloc(sizeof(struct avl_node));
    if(node == NULL) return NULL;
    node->height = 1;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

avl* avl_create(){
    avl* avl = (struct avl*)malloc(sizeof(struct avl));
    if(avl == NULL) return NULL;
    avl->root = NULL;
    avl->size = 0;
    return avl;
}

int avl_height(avl_node * node){
    if(node == NULL) return 0;
    return node->height;
}

int avl_compare_key(int key, avl_node *node){
    if(node == NULL) return 0;
    if(key > node->key) return 1;
    return 0;
}

int max(avl_node *x, avl_node *y){
    int m = avl_height(x);
    int n = avl_height(y);
    return m>n?m:n;
}

avl_node * avl_rotate_ll(avl_node *node){
    avl_node* top = node->left;
    node->left = top->right;
    top->right = node;
    node->height = max(node->left, node->right)+1;
    top->height = max(top->left, top->right)+1;
    return top;
}

avl_node * avl_rotate_rr(avl_node *node){
    avl_node *top = node->right;
    node->right = top->left;
    top->left = node;

    node->height = max(node->left, node->right)+1;
    top->height = max(top->left, top->right)+1;
    return top;
}

avl_node *avl_rotate_lr(avl_node *node){
    node->left = avl_rotate_rr(node->left);
    return avl_rotate_ll(node);
}

avl_node *avl_rotate_rl(avl_node *node){
    node->right = avl_rotate_ll(node->right);
    return avl_rotate_rr(node);
}

int avl_get_balance(avl_node *node){
    if(node == NULL) return 0;
    return avl_height(node->left)-avl_height(node->right);
}


avl_node *avl_insert(avl_node *node, int key){
    if(node == NULL){
        return avl_create_node(key);
    }
    if(key < node->key){
        node->left = avl_insert(node->left,key);
    }else if(key > node->key){
        node->right = avl_insert(node->right, key);
    }else{
        return node;
    }
    node->height = max(node->left,node->right)+1;
    int balance = avl_get_balance(node);
    if(balance > 1 && key < node->left->key){
        return avl_rotate_ll(node);
    }
    else if(balance <-1 && key > node->right->key){
        return avl_rotate_rr(node);
    }
    else if(balance >1 && key > node->left->key){
        return avl_rotate_lr(node);
    }
    else if(balance <-1 && key < node->right->key){
        return avl_rotate_rl(node);
    }
    return node;
}

void in_tra(avl_node* node){
    if(node != NULL){
        in_tra(node->left);
        printf("%d ", node->key);
        in_tra(node->right);
    }
}

