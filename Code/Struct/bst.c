#include <stdio.h>
#include <stdlib.h>
#include "bst.h"
#define BST_NODE_CHILD 0
#define BST_NODE_PARENT 1

bst* bst_create(){
    bst *bst = (struct bst*)malloc(sizeof(struct bst));
    if(bst == NULL) return NULL;
    bst->root = NULL;
    bst->size = 0;
    return bst;
}

bst_node *bst_create_node(int key){
    bst_node *node = (struct bst_node*)malloc(sizeof(struct bst_node));
    if( node == NULL) return NULL;
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    return node;
}

bst_node *bst_search_zmy(bst_node* node, int key){
    if(node == NULL){
        return NULL;
    } 
    else{
        if(node->key == key){
            return node;
        }else if (node->key < key)
        {
            bst_search_zmy(node->right, key);
        }else if (node->key > key){
            bst_search_zmy(node->left, key);
        }else{
            return NULL;
        }
    }
}

bst_node* bst_search(bst_node *node, int type, int key){
    bst_node *curr = node;
    bst_node *parent = NULL;

    if(curr == NULL) return NULL;
    while(curr != NULL){
        if(key < curr->key){
            parent = curr;
            curr = curr->left;
        }else if (key == curr->key){
            break;
        }else{
            parent = curr;
            curr = curr->right;
        }
    }
    if(type == BST_NODE_CHILD) return curr;
    return parent;
}


bst* bst_insert(bst *bst, int key){
    bst_node *curr = bst->root;
    bst_node *parent = NULL;
    if(curr == NULL){
        bst->root = bst_create_node(key);
    }else{
        parent = bst_search(bst->root, BST_NODE_PARENT, key);
        if(parent == NULL) return NULL;
        if( key < parent->key){
            parent->left = bst_create_node(key);
        }else if(key == parent->key){
            printf("repete");
            return NULL;
        }else{
            parent->right = bst_create_node(key);
        }
    }
    bst->size++;
    return bst;

}

bst_node *bst_find_max_node(bst_node *node, int type){
    bst_node *curr, *parent;
    curr=node;
    parent = NULL;
    while(curr->right){
        parent = curr;
        curr = curr->right;
    }
    if(type == BST_NODE_PARENT) return parent;
    return curr;
}


void bst_delete2(bst *bst, int key){
    bst_node * parent = bst_search(bst->root, BST_NODE_PARENT, key);
    bst_node * curr = bst_search(parent, BST_NODE_CHILD, key);
    bst_node *temp, *max;

    if(parent == NULL && curr == NULL){
        temp = bst->root; 
        bst->root = NULL;
    }else if (curr->left == NULL && curr->right == NULL)
    {
        /* code */
        if(curr->key < parent->key){
            temp = parent->left;
            parent->left = NULL;
        }else{
            temp = parent->right;
            parent->right = NULL;
        }
    }else if(curr->left == NULL){
        temp = curr->right;
        curr->key = curr->right->key;
        curr->left = curr->right->left;
        curr->right = curr->right->right;
    }else if(curr->right == NULL){
        temp = curr->left;
        curr->key = curr->left->key;
        curr->left = curr->left->left;
        curr->right = curr->left->right;
    }else{
        max = bst_find_max_node(curr->left, BST_NODE_PARENT);
        if(max == NULL){
            temp = curr->left;
            curr->key = curr->left->key;
            curr->left = curr->left->left;
        }else{
            temp = max->right;
            curr->key = max->right->key;
            max->right = max->right->left;
        }
    }
    free(temp);
    bst->size--;
    
}

void bst_delete(bst *bst, int key) {
    if (bst->root == NULL) return;  // 空树，直接返回

    bst_node *parent = bst_search(bst->root, BST_NODE_PARENT, key);
    bst_node *curr = bst_search(bst->root, BST_NODE_CHILD, key);

    if (curr == NULL) return;  // 节点不存在，直接返回

    bst_node *temp;

    // Case 1: The node to be deleted is a leaf node
    if (curr->left == NULL && curr->right == NULL) {
        if (parent == NULL) {  // 删除根节点且根节点是叶节点
            bst->root = NULL;
            temp = curr;
        } else if (curr->key < parent->key) {
            parent->left = NULL;
            temp = curr;
        } else {
            parent->right = NULL;
            temp = curr;
        }
    }
    // Case 2: The node to be deleted has only a right child
    else if (curr->left == NULL) {
        if (parent == NULL) {  // 删除根节点且根节点只有右子节点
            bst->root = curr->right;
        } else if (curr->key < parent->key) {
            parent->left = curr->right;
        } else {
            parent->right = curr->right;
        }
        temp = curr;
    }
    // Case 3: The node to be deleted has only a left child
    else if (curr->right == NULL) {
        if (parent == NULL) {  // 删除根节点且根节点只有左子节点
            bst->root = curr->left;
        } else if (curr->key < parent->key) {
            parent->left = curr->left;
        } else {
            parent->right = curr->left;
        }
        temp = curr;
    }
    // Case 4: The node to be deleted has both left and right children
    else {
        bst_node *maxParent = bst_find_max_node(curr->left, BST_NODE_PARENT);
        bst_node *max = maxParent ? maxParent->right : curr->left;

        if (maxParent == NULL) {
            curr->left = max->left;
        } else {
            maxParent->right = max->left;
        }
        
        curr->key = max->key;
        temp = max;
    }
    
    free(temp);
    bst->size--;
}



void bst_in_tra(bst_node *node){
    if(node != NULL){
        bst_in_tra(node->left);
        printf("%d\t", node->key);
        bst_in_tra(node->right);
    }
}