#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int *arr;
    int front;
    int rear;
    int size;
} queue;

typedef struct Stack {
    queue *q1;
    queue *q2;
    int size;
} Stack;

int queueInit(queue *q, int size) {
    q->size = size;
    q->arr = (int*)malloc(size * sizeof(int));
    if (q->arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    q->front = -1;
    q->rear = -1;
    return 0;
}

int stackInit(Stack *s, int size) {
    s->q1 = (queue*)malloc(sizeof(queue));
    s->q2 = (queue*)malloc(sizeof(queue));
    if (s->q1 == NULL || s->q2 == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    queueInit(s->q1, size);
    queueInit(s->q2, size);
    s->size = size;
    return 0;
}

int isEmpty(queue *q) {
    return q->front == -1;
}

void enqueue(queue *q, int value) {
    if (q->rear == q->size - 1) {
        printf("queue overflow\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->arr[q->rear] = value;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("queue underflow\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

int peek(queue *q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return -1;
    }
    return q->arr[q->front];
}



void push(Stack *s, int value) {
    // Push to queue2
    enqueue(s->q2, value);

    // Move all elements from queue1 to queue2
    while (!isEmpty(s->q1)) {
        int temp = dequeue(s->q1);
        enqueue(s->q2, temp);
    }

    // Swap the names of queue1 and queue2
    queue *temp = s->q1;
    s->q1 = s->q2;
    s->q2 = temp;
}

int pop(Stack *s) {
    if (isEmpty(s->q1)) {
        printf("Stack underflow\n");
        return -1;
    }
    return dequeue(s->q1);
}

int peekStack(Stack *s) {
    if (isEmpty(s->q1)) {
        printf("Stack is empty\n");
        return -1;
    }
    return peek(s->q1);
}

void display(Stack *s) {
    if (isEmpty(s->q1)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    for (int i = s->q1->front; i <= s->q1->rear; i++) {
        printf("%d ", s->q1->arr[i]);
    }
    printf("\n");
}

int main() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    int size;
    printf("Enter the maximum size of the stack: ");
    if (scanf("%d", &size) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            return -1;
    }
    stackInit(s, size);

    int n = 0;
    while (n != 6) {
        printf("\n\n1. Push: Add an element to the stack. \n");
        printf("2. Pop: Remove the top element from the stack.\n");
        printf("3. Peek: Retrieve the top element without removing it.\n");
        printf("4. Display: Show the elements in the stack.\n");
        printf("5. Exit the program.\n");

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
                push(s, value);
                display(s);
                break;
            }
            case 2: {
                int popped = pop(s);
                if (popped != -1) {
                    printf("Popped element: %d\n", popped);
                }
                display(s);
                break;
            }
            case 3: {
                int top = peekStack(s);
                if (top != -1) {
                    printf("Top element: %d\n", top);
                }
                break;
            }
            case 4: {
                display(s);
                break;
            }
            case 5: {
                printf("Exiting program...\n");
                break;
            }
        }
    }

    free(s->q1->arr);
    free(s->q2->arr);
    free(s->q1);
    free(s->q2);
    free(s);
    return 0;
}
