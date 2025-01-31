#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} node;

typedef struct Queue {
    node *front;  
    node *rear;   
    int size;  
} queue;

void queueInit(queue *q) {
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
}

int isEmpty(queue *q) {
    if(q->front == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(queue *q, int value) {
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Queue Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode; 
        q->rear = newNode;  
    }
    q->size++;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1; 
    }
    int removedElement = q->front->data; 
    node *temp = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp); 
    q->size--;
    return removedElement;
}

void peek(queue *q) {
    if (isEmpty(q)) {
        printf("Empty queue\n");
        return;
    }
    printf("Front element: %d\n", q->front->data);
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    node *temp = q->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void queueSize(queue *q) {
    printf("Size of queue is: %d\n", q->size);
}

int main() {
    queue *q = (queue *)malloc(sizeof(queue));
    if (q == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    queueInit(q);

    int n = 0;
    while (n != 6) {
        printf("\n\n1. Enqueue: Add an element to the queue.\n");
        printf("2. Dequeue: Remove the front element from the queue.\n");
        printf("3. Peek: Retrieve the front element without removing it.\n");
        printf("4. isEmpty: Check if the queue is empty.\n");
        printf("5. Size: Return the number of elements in the queue.\n");
        printf("6. Exit the program.\n");

        printf("Enter an operation: ");

        if (scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (n) {
            case 1: {
                printf("Enter value: ");
                int value;
                scanf("%d", &value);
                enqueue(q, value);
                display(q);
            } break;

            case 2: {
                int removed = dequeue(q);
                if (removed != -1) {
                    printf("Removed element: %d\n", removed);
                    display(q);
                }
            } break;

            case 3: {
                peek(q);
            } break;

            case 4: {
                if (!isEmpty(q)) {
                    printf("Queue is not empty\n");
                } else {
                    printf("Queue is empty\n");
                }
            } break;

            case 5: {
                queueSize(q);
            } break;

            case 6: {
                printf("Exiting program...\n");
            } break;

            default:
                printf("Invalid operation\n");
                break;
        }
    }

    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);

    return 0;
}
