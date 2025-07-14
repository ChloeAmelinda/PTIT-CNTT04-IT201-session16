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
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;

    }
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}
void enQueue(Queue* queue, int data) {
    if (queue == NULL) {//ktra cos ton tai queue ko
        return;
    }
    Node* node = createNode(data);
    if (node == NULL) {//ktra tao thanh cong ko
        return;
    }
    if (queue->rear == NULL) {//ktra co rong ko
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
int main(void) {
    Queue* queue = createQueue(3);
    if (queue == NULL) {
        return 1;
    }
    enQueue(queue, 10);
    enQueue(queue, 20);
    enQueue(queue, 30);
    printQueue(queue);

    return 0;
}