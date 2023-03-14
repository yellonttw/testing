#define _CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void print_user(User user) {
    printf("Username: %s, Level: %d, Faction: %s\n", user.name, user.level, user.factor);
}

void traverse(Queue* q, Node* node) {
    if (node == NULL) {
        return;
    }
    traverse(q, node->next);
    print_user(node->player);
}

void traverseR(Queue* q, Node* node) {
    if (node == NULL) {
        return;
    }
    print_user(node->player);
    traverseR(q, node->next);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s num_users\n", argv[0]);
        return 1;
    }
    int num_users = atoi(argv[1]);
    if (num_users <= 0) {
        printf("Invalid number of users: %s\n", argv[1]);
        return 1;
    }

    Queue q;
    queue_init(&q);
    if (enqueue_random_users(&q, num_users) != 0) {
        printf("Error: unable to enqueue users\n");
        return 1;
    }

    printf("Traversing forwards:\n");
    traverse(&q, q.head);

    printf("\nTraversing backwards:\n");
    traverseR(&q, q.head);

    return 0;
}
