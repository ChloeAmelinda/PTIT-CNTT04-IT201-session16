#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
typedef struct Queue {
    Node* front;
    Node* rear;
}Queue;
Queue* createQueue(int data) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void enQueue(Queue* queue, int data) {
    if (queue == NULL) {
        return;
    }

    Node* node = createNode(data);
    if (queue->rear == NULL) {
        queue->rear = node;
        queue->front = node;

    }else {
        queue->rear->next = node;
        queue->rear = node;
    }
}
void printQueue(Queue* queue) {
    if (queue == NULL) {
        return;
    }
    Node* node = queue->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void peek(Queue* queue) {
    if (queue == NULL) {
        return;
    }
    printf("front: %d\n", queue->front->data);
}
int main(void) {
   Queue* queue = createQueue(3);
    for (int i = 0; i <=3; i++) {
        printf("Enter number %d: ", i );
        scanf("%d", &i);
        enQueue(queue, i);
    }
    printQueue(queue);
    peek(queue);
    return 0;
}