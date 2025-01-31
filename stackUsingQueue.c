#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
    int maxSize;
} queue;

void queueInit(queue *q, int maxSize) {
    q->arr = (int *)malloc(maxSize * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->size = 0;
    q->maxSize = maxSize;
}

void enqueue(queue *q, int value) {
    if (q->size == q->maxSize) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {  
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
    q->size++;
}

int dequeue(queue *q) {
    if (q->front == -1 || q->size == 0) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;
    q->size--;
    if (q->size == 0) {  
        q->front = -1;
        q->rear = -1;
    }
    return value;
}

int isEmpty(queue *q) {
    return q->size == 0;
}

void push(queue *q, int value) {
    enqueue(q, value);
    for (int i = 0; i < q->size - 1; i++) {
        int temp = dequeue(q);
        enqueue(q, temp);
    }
}

int pop(queue *q) {
    if (isEmpty(q)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(q);
}

int peek(queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty\n");
        return -1;
    }
    return q->arr[q->front];
}

void display(queue *q) {
    if (isEmpty(q)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    queue *q = (queue *)malloc(sizeof(queue));
    if(q == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    int maxSize;
    printf("Enter the maximum size of the stack: ");
     if(scanf("%d", &maxSize) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            return -1;
     }
    queueInit(q, maxSize);

    int n = 0;
    while (n != 6) {
        printf("\n1. Push: Add an element to the stack.\n");
        printf("2. Pop: Remove the top element from the stack.\n");
        printf("3. Peek: Retrieve the top element without removing it.\n");
        printf("4. isEmpty: Check if the stack is empty.\n");
        printf("5. Size: Return the number of elements in the stack.\n");
        printf("6. Exit the program.\n");

        printf("Enter an operation:\n");

        if(scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(n) {
            case 1: {
                printf("Enter value: ");
                int value;
                scanf("%d", &value);
                push(q, value);
                if(q->size != 0) {
                    display(q);
                }
            } break;

            case 2: {
                int popped = pop(q);
                if(popped != -1) {
                    printf("Popped element: %d\n", popped);
                    display(q);
                }
            } break;

            case 3: {
                if(q->size != 0) {
                    display(q);
                }
                peek(q);
            } break;

            case 4: {
                if(isEmpty(q)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
            } break;

            case 5: {
                if(q->size != 0) {
                    display(q);
                }
                printf("Size of stack: %d\n", q->size);
            } break;

            case 6: {
                printf("Exiting program...\n");
            } break;
        }
    }
    free(q->arr);
    free(q);
    return 0;
}
