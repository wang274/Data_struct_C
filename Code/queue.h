#ifndef __Queue_H__
#define __Queue_H__

typedef struct queue_node {
    struct quque_node *next;
    void *data;
}queue_node;

typedef struct queue{
    struct queue_node *head;
    struct queue_node *tail;
    int length;
}queue;

queue* queue_create();
void* queue_release(queue*);
queue* queue_push(queue*, void*);
void* queue_pull(queue*);
void queue_empty(queue*);


#endif
