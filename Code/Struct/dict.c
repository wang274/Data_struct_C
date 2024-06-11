#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dict.h"

static unsigned int hash_integer(void *key)
{
    return (*(int *)key * 2654435769) >> 28;
}

static unsigned int hash_33(void *key)
{   
    unsigned int hash = 0;
    while (*(char *)key != 0)
    {
        /* 左移5位相当于*32，再+hash则相当于*33; */
        // hash = (hash << 5) + hash + (*(char *)key)++;
        hash = (hash << 5) + hash + *(char *)key++;
    }
    return hash;
}


dict *dict_create(int type){
    dict* dict = (struct dict*)malloc(sizeof(struct dict));
    if(dict == NULL) return NULL;
    if(type == DICT_TYPE_INT){
        dict->hash = &hash_integer;
    }else{
        dict->hash = &hash_33;
    }
    dict->size = 1024;
    dict->sizemask = dict->size -1;
    dict->table = (dict_entry**)malloc(sizeof(dict_entry*)*(dict->size));
    if(dict->table == NULL ) return NULL;
    memset(dict->table, 0, sizeof(dict_entry*)*(dict->size));
    return dict;
}

dict_entry* dict_create_entry(void *key, void *val){
    dict_entry* entry = (dict_entry*)malloc(sizeof(dict_entry));
    if(entry == NULL){
        return NULL;
    }
    entry->key = key;
    entry->val = val;
    entry->next = NULL;
    return entry;
}

dict* dict_put(dict *dict, void *key, void *val){
    unsigned int hash = dict->hash(key);
    int pos = hash & dict->sizemask;
    dict_entry *entry;
    entry = dict_create_entry(key, val);
    entry->next = dict->table[pos];
    dict->table[pos] = entry;
    return dict;
}

void * dict_get_value(dict* dict, void *key){
    unsigned int hash = dict->hash(key);
    int pos = hash & dict->sizemask;
    if(dict->table[pos] == 0) return NULL;
    dict_entry *current = dict->table[pos];
    while(current){
        if(dict->hash(current->key) == hash)
            return current->val;
        else
            current = current->next;

    }
    return NULL;

}

void dict_empty(dict *dict){
    int i;
    for(i=0; i<dict->size;i++){
        if(dict->table[i] != 0){
            dict_entry *curr, *next;
            curr = dict->table[i];
            while(curr){
                next = curr->next;
                free(curr);
                curr = next;
            }
            dict -> table[i] = 0;
        }
    }
}

void dict_release(dict* dict){
    dict_empty(dict);
    free(dict->table);
    free(dict);
}


