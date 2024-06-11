#include <stdio.h>
#include <stdlib.h>
#include "avl.c"

int main(){
    avl *avl = avl_create();
    avl_node *root = avl->root;
    root = avl_insert(root, 10);
    root = avl_insert(root, 20);
    root = avl_insert(root, 30);
    root = avl_insert(root, 40);
    root = avl_insert(root, 50);
    root = avl_insert(root, 60);
    printf("in tra: \n");
    in_tra(root);
    return 0;
}