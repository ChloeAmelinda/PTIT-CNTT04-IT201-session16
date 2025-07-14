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
    Node* node = createNode(data);
    if (queue->rear == NULL) {
        queue->rear = node;
        queue->front = node;
    }else {
        queue->rear->next = node;
        queue->rear = node;
    }

}
int isEmpty(Queue* queue) {
    return queue->rear == NULL|| queue == NULL;
}
void printQueue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
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
    int n,value;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    Queue* queue = createQueue();
    for (int i = 0; i < n; i++) {
        printf("Enter the value %d: ", i+1);
        scanf("%d",&value);
        enQueue(queue,value);
    }
    printQueue(queue);
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
    }else {
        printf("Queue is not empty\n");
    }

    return 0;
}