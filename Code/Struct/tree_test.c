#include <stdio.h>
#include "tree.c"

int main(){
    tree_node *tree;
    tree = tree_create();
    printf("\npre_tra1: ");
    pre_tra(tree);
    printf("\npre_tra2: ");
    pre_tra2(tree);
    printf("\nin_tra1: ");
    in_tra(tree);
    printf("\nin_tra2: ");
    in_tra2(tree);
    printf("\npos_tra1: ");
    pos_tra(tree);
    printf("\npos_tra2: ");
    pos_tra2(tree);
    return 0;
}