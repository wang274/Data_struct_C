#include <stdio.h>
#include <stdlib.h>
#include "dict.c"

int main(){
    dict *dict = dict_create(1);
    char str[] = "name";
    char str1[] = "Alice";
    char str2[] = "Bob";
    char str3[] = "age";
    int age = 18;

    dict_put(dict,&str,&str1);
    puts(dict_get_value(dict, &str));

    dict_put(dict, &str, &str2);
    puts(dict_get_value(dict, &str));

    dict_put(dict, &str3, &age);
    printf("age: %d\n", *(int*)dict_get_value(dict, &str3));

    dict_empty(dict);
    dict_release(dict);
    return 0;
}