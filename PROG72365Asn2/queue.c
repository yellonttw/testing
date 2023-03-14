#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "queue.h"

void queue_init(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

int queue_is_empty(Queue* q) {
    return q->head == NULL;
}

int queue_enqueue(Queue* q, User player) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->player = player;
    new_node->next = NULL;
    if (q->head == NULL) {
        q->head = new_node;
    }
    else {
        q->tail->next = new_node;
    }
    q->tail = new_node;
    return 0;
}

int queue_dequeue(Queue* q, User* player) {
    if (q->head == NULL) {
        return -1;
    }
    Node* temp = q->head;
    *player = temp->player;
    if (q->head == q->tail) {
        q->head = NULL;
        q->tail = NULL;
    }
    else {
        q->head = q->head->next;
    }
    free(temp); // free the memory
    return 0;
}

char* generate_random_username(int length) {
    char* username = (char*)malloc((length + 1) * sizeof(char));
    if (username == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    // constant array of characters containing all the uppercase and lowercase letters of the English alphabet and all the digits from 0 through 9.
    const char characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int counter = strlen(characters);
    for (int i = 0; i < length; i++) {
        int random_index = rand() % counter;
        username[i] = characters[random_index];
    }
    username[length] = '\0';
    return username;
}

int enqueue_random_users(Queue* q, int num_users) {
    srand(time(NULL));
    for (int i = 0; i < num_users; i++) {
        User user;
        user.name = generate_random_username(10);
        user.level = rand() % 60 + 1;
        const char* factions[] = { "red", "blue", "green" };
        user.factor = factions[rand() % 3];
        if (queue_enqueue(q, user) != 0) {
            return -1; // error: unable to enqueue user
        }
    }
    return 0;
}
