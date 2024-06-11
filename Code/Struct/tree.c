#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "stack.c"
#include "queue.c"
tree_node *tree_create_node(char key){
    tree_node *node = (tree_node *)malloc(sizeof(tree_node));
    if(node == NULL) return NULL;
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//不断从键盘读取数值，直到遇到#
tree_node *tree_create(){
    char str;
    tree_node *curr;
    scanf("%c", &str);
    if('#' == str){
        curr = NULL;
    }else{
        curr = tree_create_node(str);
        curr->left = tree_create();
        curr->right = tree_create();
    }
    return curr;
}

void pre_tra(tree_node *node){
    if(node != NULL){
        printf("%c\t", node->key);
        pre_tra(node->left);
        pre_tra(node->right);
    }
}

void in_tra(tree_node *node){
    if(node != NULL){
        in_tra(node->left);
        printf("%c\t", node->key);
        in_tra(node->right);
    }
}

void pos_tra(tree_node *node){
    if( node != NULL){
        pos_tra(node->left);
        pos_tra(node->right);
        printf("%c\t", node->key);
    }
}


void pre_tra2(tree_node *node){
    stack *stack = stack_create();
    tree_node* curr = node;
    while(curr != NULL || stack->length){
        if(curr != NULL){
            printf("%c\t", curr->key);
            stack_push(stack, curr);
            curr = curr->left;
        }else{
            curr = stack_pop(stack);
            curr = curr->right;
        }
    }
    stack_release(stack);
}

void in_tra2(tree_node* node){
    stack *stack = stack_create();
    tree_node *curr = node;
    while(curr != NULL || stack->length){
        if(curr != NULL){
            stack_push(stack, curr);
            curr = curr ->left;
        }else{
            curr = stack_pop(stack);
            printf("%c\t", curr->key);
            curr = curr ->right;
        }
    }
    stack_release(stack);
}

void pos_tra2(tree_node *node){
    stack *s = stack_create();
    stack *stack = stack_create();

    tree_node* curr = node;
    while(curr != NULL || stack->length){
        if(curr != NULL){
            stack_push(s, &(curr->key));
            stack_push(stack,curr);
            curr = curr->right;
        }else{
            curr = stack_pop(stack);
            curr = curr->left;
        }
    }
    while(s->length){
        printf("%c\t",*(char*)stack_pop(s));
    }
    stack_release(s);
    stack_release(stack);
}

void level_tra(tree_node *root){
    queue *queue = queue_create();
    if(root != NULL){
        queue_push(queue,root);
    }
    while(queue->length){
        tree_node *curr = queue_pull(queue);
        printf("%c\t", curr->key);
        if(curr->left) queue_push(queue, curr->left);
        if(curr->right) queue_push(queue, curr->right);

    }
    queue_release(queue);
}






