#include <stdio.h>
#include <stdlib.h>
#include "list.h"

list* list_create(void){
    list *list = (struct list*)malloc(sizeof(struct list));
    if(list == NULL) return NULL;
    list->head = list->tail =NULL;
    list->length = 0;
    return list;
}

list* list_add_head(list* list, void* value){
    list_node* node = (list_node*)malloc(sizeof(list_node));
    if(node ==NULL) return NULL;
    node -> value = value;

    if(list->length == 0){
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }else{
        node->prev = NULL;
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->length++;
    return list;
}

list* list_add_tail(list* list, void* value){
    list_node * node = (list_node *)malloc(sizeof(list_node));
    if(node == NULL) return NULL;
    node->value = value;
    if(list->length == 0){
        list->head = list->tail = node;
        node->prev = node->next = NULL;
    }else{
        node->next = NULL;
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    list->length++;
    return list;
}

list* list_del_node(list* list, list_node* node){
    if(node->prev){
        node->prev->next=node->next;
    }else{
        list->head = node->next;
    }
    if(node->next){
        node->next->prev=node->prev;
    }else{
        list->tail = node->prev;
    }

    free(node);
    list->length--;
    return list;
}

void *list_get_head(list *list){
    if(list->head == NULL) return NULL;
    void *value = list->head->value;
    list_del_node(list,list->head);
    return value;
}

void *list_get_tail(list *list){
    if(list->tail == NULL) return NULL;
    void *value = list->tail->value;
    list_del_node(list, list->tail);
    return value;
}

void list_empty(list *list){
    unsigned long length;
    list_node *curr, *next;
    curr = list -> head;
    length = list ->length;
    while(length--){
        next = curr->next;
        free(curr);
        curr = next;
    }
    list ->head = list->tail = NULL;
    list -> length = 0;
}

void list_release(list*list){
    list_empty(list);
    free(list);
}

list_iter* list_get_iterator(list* list, int direction){
    list_iter *iter = (list_iter*)malloc(sizeof(list_iter));
    if(iter == NULL) return NULL;
    if(direction == LIST_START_HEAD){
        iter->next = list->head;
    }else{
        iter->next = list->tail;
    }
    iter->direction = direction;
    return iter;
}

void *list_next(list_iter *iter){
    list_node *curr = iter->next;
    if( curr == NULL) return NULL;
    if(iter->direction == LIST_START_HEAD)
        iter->next = curr->next;
    else
        iter->next = curr ->prev;
    return curr->value;
}

void list_release_iterator(list_iter *iter){
    free(iter);
}



