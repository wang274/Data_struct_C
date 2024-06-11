#ifndef __List_H__
#define __List_H__
#define LIST_START_HEAD 0 
#define LIST_START_TAIL 1 

typedef struct list_node {
    struct list_node *prev;
    struct list_node *next;
    void *value;
    
}list_node;

typedef struct list{
    unsigned long length;
     list_node *head;
     list_node *tail;
}list;

typedef struct list_iter{
    list_node *next;
    int direction;
}list_iter;

list* list_create();
void list_empty(list* list);
void list_release(list* list);
list* list_add_head(list*, void*);
list* list_add_tail(list*, void*);
void* list_get_head(list*);
void* list_get_tail(list*);
list* list_del_node();
list_iter* list_get_iterator(list*, int);
void list_release_iterator(list_iter*);
void* list_next(list_iter*);
#endif