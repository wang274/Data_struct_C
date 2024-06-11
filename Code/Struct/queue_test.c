#include <stdio.h>
#include "queue.c"

int main(){
    char a = 'a';
    char b = 'b';
    char c = 'c';
    queue *queue = queue_create();
    printf("%p\n", queue_pull(queue));
    queue_push(queue, &a);
    queue_push(queue, &b);
    queue_push(queue, &c);
    while(queue->length){
        printf("%c\n", *(char *)queue_pull(queue));

    }
    queue_push(queue, &a);
    queue_push(queue, &c);
    queue_empty(queue);
    printf("%p\n", queue_pull(queue));

    queue_release(queue);

    return 0;
}