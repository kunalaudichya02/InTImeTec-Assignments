#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Stack{
    int top;
    int arr[MAX];
} stack;

stack *stackInit(stack *s){
    s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    return s;
}

int isEmpty(stack *s){
    return s->top == -1;
}

void push(stack *s, int x){
    if (s->top == MAX - 1)
    {
        printf("stack overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

int pop(stack *s){
    if (s->top == -1)
    {
        printf("stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

void enqueue(stack *s, int x){
    push(s, x);
}

int dequeue(stack *s){
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = pop(s);
    if (isEmpty(s))
    {
        return x;
    }
    int temp = dequeue(s);
    push(s, x);
    return temp;
}

int peek(stack *s){
    if (isEmpty(s))
    {
        printf("Queue is Empty\n");
        return -1;
    }
    int x = pop(s);
    if (isEmpty(s))
    {
        push(s, x);
        return x;
    }
    int temp = peek(s);
    push(s, x);
    return temp;
}

int size(stack *s){
    return s->top + 1;
}

void display(stack *s) {
    if (isEmpty(s)) {
        printf("Queue is Empty\n");
        return;
    }

    int x = pop(s); 
    display(s);   
    printf("%d ", x);
    push(s, x);    
}

int main()
{
    stack *s = NULL;
    s = stackInit(s);
    int n=0;
    while (n!=6)
    {
        printf("\n\n1. Enqueue: Add an element to the queue.\n");
        printf("2. Dequeue: Remove the front element from the queue.\n");
        printf("3. Peek: Retrieve the front element without removing it.\n");
        printf("4. Size: Return the number of elements in the queue.\n");
        printf("5. isEmpty: Check if the queue is empty.\n");
        printf("6. Exit the program.\n");

        int n;
        printf("Enter an operation: ");
        if (scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); 
            return -1;
        }
        int x;
        switch (n)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &x);
            enqueue(s, x);
            display(s);
            break;
        case 2:{
            int dequeued = dequeue(s);
            if (dequeued != -1)
            {
                printf("Dequeued: %d\n", dequeued);
            }
            display(s);
            break;}
        case 3:{
            int front = peek(s);
            if (front != -1)
            {
                printf("Front : %d\n", front);
            }}
            break;
        case 4:
            display(s);
            printf("Size of Queue: %d\n", size(s));
            break;

        case 5:
            if (isEmpty(s))
            {
                printf("Queue is Empty\n");
            }
            else
            {
                printf("Queue is not Empty\n");
            }
            break;

        case 6:
             printf("Exiting...\n");
             return 0;
        }
    }

    return 0;
}