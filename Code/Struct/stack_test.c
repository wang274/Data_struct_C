#include <stdio.h>
#include <stdlib.h>
#include "stack.c"

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