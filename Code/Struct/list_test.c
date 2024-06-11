#include <stdio.h>
#include <stdlib.h>
#include "list.c"

int main(){
    char a = 'A';
    char b = 'B';
    char c = 'C';
    list *list = list_create();
    printf("-----------\n");
    list_add_head(list, &a);
    list_add_head(list, &b);
    list_add_head(list, &c);
    list_add_tail(list, &a);
    list_add_tail(list, &b);
    list_add_tail(list, &c);
    printf("----the length of list: %d --------- \n", list->length);
    printf("----get the value of head-------\n");
    while(list->length>3){
        printf("%c\n", *(char*)list_get_head(list));
    }
    printf("-----get the value of tail-----\n");
    while(list->length){
        printf("%c\n", *(char*)list_get_tail(list));
    }
    list_add_head(list, &a);
    list_add_head(list, &b);
    list_add_head(list, &c);
    list_iter* iter = list_get_iterator(list, LIST_START_TAIL);
    printf("--------iter-------\n");
    printf("%c\n", *(char*)list_next(iter));
    printf("%c\n", *(char*)list_next(iter));
    printf("%c\n", *(char*)list_next(iter));
    list_release_iterator(iter);
    list_empty(list);

    printf("--------to test if empty error-------\n");
    printf("%p\n", list_get_head(list));
    printf("%p\n", list_get_tail(list));

    list_release(list);

    return 0;
}