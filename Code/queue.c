#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue *queue_create(){
    queue *queue = (struct queue*)malloc(sizeof(struct  queue_node));
    queue_node *node = (queue_node*)malloc(sizeof(queue));
    if(queue == NULL || node == NULL){
        return NULL;
    } 
    node ->data = NULL;
    node ->next = NULL;
    queue->head = queue->tail = node;
    queue->length = 0;
    return queue;
}



queue *queue_push(queue *queue, void *data){
    queue_node *node = (queue_node*)malloc(sizeof(queue_node));
    if(node == NULL) return NULL;
    node ->data = data;
    queue->tail -> next = node;
    node ->next = NULL;
    queue ->tail = queue->tail->next;
    queue ->length++;
    return queue;
}

void *queue_pull(queue *queue){
    queue_node *curr = queue->head->next;
    if(curr == NULL) return NULL;
    void *data = curr->data;
    queue->head->next = curr->next;
    if(queue->tail == curr){
        queue->tail = queue -> head;
    }

    free(curr);
    queue->length--;
    return data;
}

void  queue_empty(queue *queue){
    int length = queue->length;
    queue_node *curr, *next;
    curr = queue->head->next;
    while(length--){
        next = curr->next;
        free(curr);
        curr = next;
    }

    queue ->head ->next = NULL;
    queue->head->data=NULL;
    queue->tail = queue->head;
    queue->length = 0;

}

void *queue_release(queue *queue){
    queue_empty(queue);
    free(queue->head);
    free(queue);
}