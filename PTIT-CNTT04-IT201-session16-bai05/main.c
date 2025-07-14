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
    node->data = data;
    node->next = NULL;
    return node;
}
void enQueue(Queue* queue, int data) {
    if (queue== NULL) {
        return;
    }
    Node* node = createNode(data);

    if (node == NULL) {
        return;
    }
    if (queue->rear == NULL) {
        queue->front =node;
        queue->rear = node;
    }else{
        queue->rear->next = node;
        queue->rear = node;
    }
}
int isEmptyQueue(Queue* queue) {
    return queue->front == NULL||queue == NULL;
}
void printQueue(Queue* queue) {
    Node* node = queue->front;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void deQueue(Queue* queue) {
    if (isEmptyQueue(queue)) {
        return;
    }
    Node* node = queue->front;
    int data = node->data;
    queue->front = queue->front->next;
    if (queue->rear == NULL) {
        queue->rear = NULL;
    }
    return data;
}
int main(void) {
    int n,value;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    Queue* queue = createQueue();
    for (int i = 0; i < n; i++) {
        printf("Enter the value for element %d: ", i+1);
        scanf("%d",&value);
        enQueue(queue,value);
    }
    printQueue(queue);
    if (isEmptyQueue(queue)) {
        printf("Queue is empty\n");
    }else {
        printf("Queue is not empty\n");
    }
    deQueue(queue);
    printQueue(queue);
    return 0;
}