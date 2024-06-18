#include <stdio.h>
#include <string.h>
#include "Struct/stack.c"
#define RAII_VARIABLE(vartype,varname,initval,dtor)  void _dtor_ ## varname (vartype * v) { dtor(*v); } vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

void raiiExample(){
    RAII_VARIABLE(char*, name, (char*)malloc(32), free);
    strcpy(name, "RAII Example");
    printf("%s\n", name);
}

int square(int num){
    return num*num;
}

int add(int num1, int num2){
    return num1+num2;
}

int sub(int num1, int num2){
    return num1-num2;
}

typedef int (*fptr)(int,int);

int compute(fptr fptr1, int num1, int num2){
    return fptr1(num1, num2);
}

fptr select(char opcode){
    switch (opcode)
    {
    case '+'/* constant-expression */:
        return add;/* code */
        break;
    case '-':
        return sub;
        break;
    default:
        break;
    }
}

int evaluate (char opcode, int num1, int num2){
    fptr fptr2 = select(opcode);
    return fptr2(num1, num2);
}







int main(){
    //  char *names[] = {"Miller", "Jones", "Anderson"};
    //  printf("%c\n", *(*(names+1)+2));
    //  printf("%c\n", names[1][2]);

    //  int num = 0;
    //  int* pi = &num;
    //  printf("%d\n", *pi);

    // printf("Value of pi: %p\n", pi);
    // void *pv = pi;
    // pi = (int*)pv;
    // printf("Value of pi: %p\n", pi);
    
    // intptr_t *pe = &num;
    // uintptr_t *pu = (uintptr_t*)&num;
    // short s;
    // short *ps = &s;
    // char c;
    // char *pc = &c;
    // printf("Content of ps before: %d\n", ps);
    // ps = ps+1;
    // printf("Content of after: %d\n", ps);
    // printf("Content of pc before: %d\n", pc);
    // pc = pc+1;
    // printf("Content of pc after: %d\n", pc);

    // char *titles[] = { "A Tale of Two Cities", "Wuthering Heights", "Don Quixote", "Odyssey", "Moby-Dick", "Hamlet", "Gulliver's Travels"};
    // char **bestBooks[3];
    // char **englishBooks[4];
    
    // bestBooks[0] = &titles[0];

    // int num = 10;
    // int *const cpi = &num;
    // printf("%d\n", *cpi);
    // num = 20;
    // printf("%d\n", *cpi);
    // // int new_num = 20;
    // // cpi = &new_num;
    // *cpi = 30;
    // char *name = (char*)malloc(sizeof(char));
    // printf("Enter the name:");
    // // scanf("%s",name);
    // char *string1;
    // char *string2;
    // string1 = (char*)malloc(16);
    // strcpy(string1, "0123456789AB");
    // string2 = realloc(string1, 8);
    // printf("string1 Value: %p [%s]\n", string1, string1);
    // printf("string2 Value: %p [%s]\n", string2, string2);
    // string2 = realloc(string1, 1024);
    // printf("string1 Value: %p [%s]\n", string1, string1);
    // printf("string2 Value: %p [%s]\n", string2, string2);
    // raiiExample();
    // int *ptr;  // 声明一个指向常量整数的指针
    // int constant = 10;  // 声明一个整数常量

    // ptr = &constant;  // 将整数常量的地址赋给指针

    // // 尝试修改常量值，编译器会报错
    // *ptr = 20;  // 编译错误：assignment of read-only location
    int (*fptr1)(int);
    fptr1 = square;
    int n = 5;
    printf("%d squared is %d \n", n, fptr1(n));
    printf("%d\n", compute(add, 5, 6));
    printf("%d\n", compute(sub, 5, 6));
    printf("%d\n", evaluate('+', 5, 6));
    printf("%d\n", evaluate('-', 5, 6));
    
    fptr fptr3 = add;
    if(fptr3 == add){
        printf("fptr3 points to add function\n");

    }else{
        printf("fptr3 does not point to add function\n");
    };
    int (*(arr2[])) = {
        (int []) {0,1,2,3},
        (int []) {4,5},
        (int []) {6,7,8}
    };

    char name[32];
    char *names[30];
    size_t count = 0;
    do{printf("Enter a name:");
    scanf("%s", name);
    names[count] = (char*)malloc(strlen(name)+1);
    strcpy(names[count], name);
    count++;}
    while(strcmp(name, "quit"));
    

    
    return 0;
}
