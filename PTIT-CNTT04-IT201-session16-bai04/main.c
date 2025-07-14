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
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}
void enQueue(Queue* queue, int data) {
    if (queue == NULL) {
        return;
    }

    Node* node = createNode(data);
    if (node == NULL) {
        return;
    }
    if (queue->rear == NULL) {
        queue->rear = node;
        queue->front = node;
    }else {
        queue->rear->next = node;
        queue->rear = node;
    }
}
int isEmpty(Queue* queue) {
    return queue->front == NULL || queue == NULL;
}
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
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
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("front = %d\n", queue->front->data);
}

int main(void) {
    int n;
    printf("Enter the number of queue: ");
    scanf("%d", &n);
    Queue* queue = createQueue();
    int value;
    for (int i = 0; i < n; i++) {
        printf("Enter %d: ",i+1);
        scanf("%d", &value);
        enQueue(queue,value);
    }
    printQueue(queue);
    peek(queue);
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }else{
        printf("Queue is not empty\n");


    }
    return 0;
}