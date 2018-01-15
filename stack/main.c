#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


#define STACK_DEFAULT_SIZE 32
#define STACK_EMPTY "stack_empty"
#define MEMORY_ERROR "memory_error"

struct stack {
    int *data;
    size_t quantity;    //колличество элементов
    size_t size;        //размер буфера
};

struct stack *init() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->quantity = 0;
    s->size = STACK_DEFAULT_SIZE;
    s->data = (int *)malloc(sizeof(int)*s->size);
    if (s->data==NULL) {
        printf(MEMORY_ERROR);
        exit(1);
    }
    return s;
}

void delete(struct stack *s){
    free(s->data);
    free(s);
}

void push (struct stack *s, int element) {
    if (s->quantity == s->size) {
        s->data = (int *)realloc(s->data, s->size*sizeof(int)*2);
        s->size *= 2;
        if (s->data == NULL) {
            printf(MEMORY_ERROR);
            exit(1);
        }
    }
    s->data[s->quantity++] = element;
}

int pop (struct stack *s) {
    if (s->quantity != 0) {
        s->quantity--;
        return s->data[s->quantity];
    } else {
        printf(STACK_EMPTY);
        return NULL;
    }
}

int main() {
    struct stack *s = init();
    for(int i = 0; i < 128; i++){
        push(s, i);
    }
    for(int i = 0; i < 128; i++){
        printf("%d ", pop(s));
    }
    pop(s);
    delete(s);
    return 0;
}