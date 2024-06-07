#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *next;
    int data;
}list;

list * create_list(){
    list *head = (list*)malloc(sizeof(list));
    if (head == NULL)
        return NULL;
    head->data = 0;
    head->next = NULL;
    return head;
}

list * insert_list(list *head, int data, int pos){
    int i;
    list *curr = head;
    if( pos > curr->data) return NULL;
    list *node = (list*)malloc(sizeof(list));
    if (node == NULL) return NULL;
    node->data = data;
    node->next = NULL;

    for (i=0; i < pos; i++){
        curr = curr->next;
    }

    
    node->next = curr->next;
    curr->next = node;
    head->data++;
    return head;

}

void print_list(list *head){
    list *curr = head->next;
    while (curr){
        printf("%d \t", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

list * delete_list(list *head, int pos){
    int i;
    list *curr = head;
    if (pos > curr->data) return NULL;
    for (i=0; i<pos; i++){
        curr = curr->next;
    }

    list *temp = curr ->next;
    curr ->next = curr -> next -> next;

    free(temp);
    head->data--;
    return head;

}

int main(){
    list *h = create_list();
    printf("the length of list: %d\n", h->data);
    for(int j = 0; j < 10; j++){
        insert_list(h, j, j);
    }
    delete_list(h, 5);
    printf("the length of list: %d \n", h->data);
    print_list(h);
    printf("hello world");
    return 0;
}
