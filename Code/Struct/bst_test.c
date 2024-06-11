#include <stdio.h>
#include <stdlib.h>
#include "bst.c"

int main(){
    bst *bst = bst_create();
    int arr[] = {21, 3, 5, 26, 29, 50, 18, 53, 8, 67, 1, 78, 6};
    int length = sizeof(arr)/sizeof(int);
    int i;
    
    for(i=0; i<length; i++){
        bst_insert(bst,arr[i]);
        printf("size: %d ", bst->size);
        printf("in tra: ");
        bst_in_tra(bst->root);
        printf("\n");
    }

    for(i = length-1; i>=0; i--){
        bst_delete(bst, arr[i]);
        printf("size : %d ", bst->size);
        printf("in tra: ");
        bst_in_tra(bst->root);
        printf("\n");
    }
    free(bst);
    return 0;
}