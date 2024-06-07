#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    struct stack_node *next;
    void *data;
}stack_node;

typedef struct stack {
    struct stack_node *top;
    int length;
}stack;

stack * stack_create(){
    stack *stack = (struct stack*)malloc(sizeof(struct stack));
    if(stack == NULL) return NULL;
    stack->length = 0;
    stack->top = NULL;
    return stack;
}

stack * stack_push(stack *stack, void *data){
    stack_node *node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(node == NULL) return NULL;
    node -> data = data;
    node->next = stack->top;
    stack->top = node;
    stack->length++;
    return stack;
}

stack * stack_pop(stack *stack){
    stack_node *curr = stack->top;
    if(curr == NULL) return NULL;
    void *data = curr->data;
    stack->top = stack->top->next;
    free(curr);
    stack->length--;
    return data;
}

void * stack_empty(stack *stack){
    int length = stack->length;
    stack_node *curr, *next;
    curr = stack->top;
    while(length--){
        next = curr->next;
        free(curr);
        curr = next;
    }

    stack->length = 0;
    stack->top = NULL;
    
}

void stack_release(stack *stack){
    stack_empty(stack);
    free(stack);
}


int main(){
    char a = 'a';
    char b = 'b';
    char c = 'c';
    
    stack *stack = stack_create();
    printf("%p\n",stack_pop(stack));

    stack_push(stack, &a);
    printf("%p\n",stack_pop(stack));
    stack_push(stack, &b);
    stack_push(stack, &c);

    while(stack->length){
        printf("%c\n", *(char*)stack_pop(stack));
    }
    
    stack_push(stack, &a);
    stack_empty(stack);
    printf("%p\n", stack_pop(stack));
    
    stack_release(stack);
    return 0;
}