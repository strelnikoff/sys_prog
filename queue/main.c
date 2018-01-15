#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct Queue {
    struct Node *head;
    struct Node *tail;
};

struct Queue* createQueue() {
    struct Queue *tmp = (struct Queue*) malloc(sizeof(struct Queue));
    tmp->head = tmp->tail = NULL;
    return tmp;
};


int popFirst(struct Queue *list) {
    struct Node *prev;
    int tmp;
    if (list->head == NULL) {
        exit(2);
    }

    prev = list->head;
    list->head = list->head->next;
    if (list->head) {
        list->head->prev = NULL;
    }
    if (prev == list->tail) {
        list->tail = NULL;
    }
    tmp = prev->value;
    free(prev);
    return tmp;
};

int popLast(struct Queue *list) {
    struct Node *next;
    int tmp;
    if (list->tail == NULL) {
        exit(4);
    }

    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
    return tmp;
};

void deleteLinkedList(struct Queue **list) {
    struct Node *tmp = (*list)->head;
    struct Node *next = NULL;
    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
    free(*list);
    (*list) = NULL;
};

void pushFront(struct Queue *list, int data) {
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    if (tmp == NULL) {
        exit(1);
    }
    tmp->value = data;
    tmp->next = list->head;
    tmp->prev = NULL;
    if (list->head) {
        list->head->prev = tmp;
    }
    list->head = tmp;

    if (list->tail == NULL) {
        list->tail = tmp;
    }
};
void pushBack(struct Queue *list, int data) {
    struct Node *tmp = (struct Node*) malloc(sizeof(struct Node));
    if (tmp == NULL) {
        exit(3);
    }
    tmp->value = data;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;

    if (list->head == NULL) {
        list->head = tmp;
    }
};
void printQueue(struct Queue *list) {
    struct Node *tmp = list->head;
    do {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    } while (tmp != list->head->prev);
}
void main() {
    struct Queue *list = createQueue();
    for (int i = 0; i<10; i++) {
        pushFront(list, i);
    }
    for (int i = -1; i>-10; i--) {
        pushBack(list, i);
    }
    printQueue(list);
    printf("\n");
    for (int i = 0; i<10; i++) {
        printf("%d ", popFirst(list));
    }
    printf("\n");
    for (int i = 0; i<10; i++) {
        printf("%d ", popFirst(list));
    }
    printf("\n");
    for (int i = 0; i<10; i++) {
        printf("%d ", popLast(list));
    }
    deleteLinkedList(&list);

    return;
};