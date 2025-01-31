#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *arr;
    int top;
    int size;
} stack;

void stackInit(stack *s, int size) {
    s->size = size;
    s->arr = (int*)malloc(size * sizeof(int));
    if (s->arr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    s->top = -1;
}

int isEmpty(stack *s) {
    return s->top == -1;
}

void push(stack *s, int value) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

typedef struct queue {
    stack *s1;
    stack* s2;
} queue;

void queueInit(queue *q, int size) {
    q->s1 = (stack*)malloc(sizeof(stack));
    q->s2 = (stack*)malloc(sizeof(stack));
    stackInit(q->s1, size);
    stackInit(q->s2, size);
}

void enqueue(queue *q, int value) {
    push(q->s1, value);
}

int dequeue(queue *q) {
    if (isEmpty(q->s2)) {
        // transfer all elements from s1 to s2(one by one) if s2 is empty
        while (!isEmpty(q->s1)) {
            int temp = pop(q->s1);
            push(q->s2, temp);
        }
    }
    if (isEmpty(q->s2)) {
        printf("queue underflow\n");
        return -1;
    }
    int popped = pop(q->s2);
    return popped;
}

int queueIsEmpty(queue *q) {
    return isEmpty(q->s1) && isEmpty(q->s2);
}

int peek(queue *q) {
    if (isEmpty(q->s2)) {
        while (!isEmpty(q->s1)) {
            int temp = pop(q->s1);
            push(q->s2, temp);
        }
    }
    if (isEmpty(q->s2)) {
        printf("queue is empty\n");
        return -1;
    }
    int top = q->s2->arr[q->s2->top];
    return top;
}

void display(queue *q) {
    if (isEmpty(q->s1) && isEmpty(q->s2)) {
        printf("queue is empty\n");
        return;
    }

    printf("queue: ");
    for (int i = 0; i <= q->s2->top; i++) {
        printf("%d ", q->s2->arr[i]);
    }
    for (int i = q->s1->top; i >= 0; i--) {
        printf("%d ", q->s1->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int size;
    printf("Enter queue size: ");
    if (scanf("%d", &size) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            return -1;
    }

    queue *q;
    if (q == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    queueInit(q, size);

    int n=0;
    while (n!=5) {
        printf("\n\n1. Enqueue: Add an element to the queue.\n");
        printf("2. Dequeue: Remove the front element from the queue.\n");
        printf("3. Peek: Retrieve the front element without removing it.\n");
        printf("4. isEmpty: Check if the queue is empty.\n");
        printf("5. Exit the program.\n");

        printf("Enter an operation: ");

        if (scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (n) {
            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(q, value);
                display(q);
                break;
            }
            case 2: {
                int dequeued = dequeue(q);
                if (dequeued != -1) {
                    printf("Dequeued: %d\n", dequeued);
                }
                display(q);
                break;
            }
            case 3: {
                int front = peek(q);
                if (front != -1) {
                    printf("Front: %d\n", front);
                }
                break;
            }
            case 4:{
                int x = queueIsEmpty(q);
                if(x ==0){
                    printf("Queue is not empty\n");
                }
                display(q);}
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
        }
    }
    return 0;
}
