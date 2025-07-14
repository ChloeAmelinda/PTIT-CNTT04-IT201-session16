#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct Queue {
    int size;
    Node* front;
    Node* rear;
    int* arr;
}Queue;
Queue *createQueue(int size) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    return queue;

    ;
}
int main(void) {
    printf("Hello, World!\n");
    return 0;
}