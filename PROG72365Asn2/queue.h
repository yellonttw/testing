#pragma once
#include <stdlib.h>

typedef struct user {
    char* name;
    int level;
    char* factor;
} User;

typedef struct node {
    User player;
    struct node* next;
} Node;

typedef struct queue {
    Node* head;
    Node* tail;
} Queue;

void queue_init(Queue* q);
int queue_is_empty(Queue* q);
int queue_enqueue(Queue* q, User player);
int queue_dequeue(Queue* q, User* player);
int enqueue_random_users(Queue* q, int num_users);
