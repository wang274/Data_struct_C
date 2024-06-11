#ifndef __DICT_H__
#define DICT_TYPE_INT 0
#define DICT_TYPE_STR 1

typedef struct dict_entry{
    struct dict_entry* next;
    void *key;
    void *val;

}dict_entry;

typedef struct dict{
    unsigned int (*hash)(void*key);
    dict_entry **table;
    int size;
    int sizemask;
}dict;


void dict_release(dict* dict);
void dict_empty(dict *dict);
void * dict_get_value(dict* dict, void *key);
dict* dict_put(dict *dict, void *key, void *val);
dict_entry* dict_create_entry(void *key, void *val);
dict *dict_create(int type);
#endif