#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int *arr;
    int front;
    int rear;
    int size;
} queue;

int queueInit(queue * q, int size){
    q->size = size;
    q->arr = (int*)malloc(size*sizeof(int));
    if (q->arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    q->front = -1;
    q->rear = -1;
    return 0;
}

int isEmpty(queue *q){
    if(q->front == q->rear){
        return 1; //queue empty
    }
    else{
        return 0; //queue isn't empty
    }
}
int isFull(queue *q){
    if( q->rear == q->size-1){
        return 1; //queue full
    }
    else{
        return 0; //queue isn't full
    }
}
void display(queue *q){
    if (isEmpty(q)) {
    printf("queue is empty\n");
    return;
    }
    printf("queue: ");
    for(int i=q->front+1; i<=q->rear; i++){
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
void enqueue(queue *q, int value){
    if(!(isFull(q))){
        q->rear++;
        q->arr[q->rear] = value;
    }
    else{
        printf("queue overflow\n");
    }
}

int dequeue(queue *q){
    if(!(isEmpty(q))){
        int removedElement = q->arr[q->front+1];
        q->front++;
        return removedElement;
    }
    else{
        printf("queue underflow\n");
    }
}
void peek(queue *q){
    if(!(isEmpty(q))){
        printf("Front element: %d\n", q->arr[q->front+1]);
    }
    else{
        printf("Empty queue\n");
    }
}

void queueSize(queue *q){
    if(!(isEmpty(q))){
        printf("Size of queue is: %d\n", (q->rear - q->front));
    }
    else{
        printf("Size of queue is 0\n");
    }
}
int main(){
    queue *q = (queue *)malloc(sizeof(queue));
    if(q==NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
    int size;
    printf("Enter maximum size of the queue: ");
    if(scanf("%d", &size) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            return -1;
    }
    queueInit(q, size);

    int n=0;
    while(n!= 6){
        printf("\n\n1.enqueue: Add an element to the queue.\n");
        printf("2. dequeue: Remove the front element from the queue.\n");
        printf("3. peek: Retrieve the front element without removing it.\n");
        printf("4. isEmpty: Check if the queue is empty.\n");
        printf("5. size: Return the number of elements in the queue.\n");
        printf("6. Exit the program. \n");
        
        printf("Enter an operation:\n");
    
        if(scanf("%d", &n) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch(n){
            case 1:{
                printf("Enter value: ");
                int value;
                scanf("%d", &value);
                enqueue(q, value);
                if(!(isEmpty(q))){
                    display(q);
                }
            }
            break;

            case 2:{
                int removed = dequeue(q);
                printf("Removed element: %d\n", removed);
                if(!(isEmpty(q))){
                    display(q);
                }
            }
            break;

            case 3:{
                if(!(isEmpty(q))){
                    display(q);
                }
                peek(q);
            }
            break;

            case 4:{
                if(!isEmpty(q)){
                    printf("queue is not empty");
                }
                else{
                    printf("queue is empty");
                };
            }
            break;

            case 5:{
                if(!(isEmpty(q))){
                    display(q);
                }
                queueSize(q);
            }
            break;

            case 6:{
                printf("Exiting program...");
            }
            break;

        }
    }
    free(q->arr);
    free(q);

    return 0;
}