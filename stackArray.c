#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int *arr;
    int top;
    int size;
} stack;

int stackInit(stack * s, int size){
    s->size = size;
    s->arr = (int*)malloc(size*sizeof(int));
    if (s->arr == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }
    s->top = -1;
}

int isEmpty(stack *s){
    if(s->top == -1){
        return 1; //stack empty
    }
    else{
        return 0; //stack isn't empty
    }
}
void display(stack *s){
    printf("Stack: ");
    for(int i=0; i<=s->top; i++){
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
void push(stack *s, int value){
    if((s->size - s->top)>1){
        s->top++;
        s->arr[s->top] = value;
    }
    else{
        printf("Stack overflow\n");
    }
}


int pop(stack *s){
    if(s->top >=0){
        int poppedElement = s->arr[s->top];
        s->top--;
        return poppedElement;
    }
    else{
        printf("Stack underflow\n");
    }
}
void peek(stack *s){
    if(s->top >= 0){
        printf("Top element: %d\n", s->arr[s->top]);
    }
    else{
        printf("Empty Stack\n");
    }
}

void stackSize(stack *s){
    if(s->top >= 0){
        printf("Size of stack is: %d\n", (s->top + 1));
    }
    else{
        printf("Size of stack is 0\n");
    }
}
int main(){
    stack *s = (stack *)malloc(sizeof(stack));
    if(s==NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
    int size;
    printf("Enter maximum size of the stack: ");
    scanf("%d", &size);
    stackInit(s, size);

    int n=0;
    while(n!= 6){
        printf("\n\n1. push: Add an element to the stack. \n");
        printf("2. pop: Remove the top element from the stack.\n");
        printf("3. peek: Retrieve the top element without removing it.\n");
        printf("4. isEmpty: Check if the stack is empty.\n");
        printf("5. size: Return the number of elements in the stack.\n");
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
                push(s, value);
                if(s->top != -1){
                    display(s);
                }
            }
            break;

            case 2:{
                if(!isEmpty(s)){
                    int popped = pop(s);
                    printf("Popped element: %d\n", popped);
                    display(s);
                }
                else{
                    printf("Stack Underflow\n");
                }
            }
            break;

            case 3:{
                if(!isEmpty(s)){
                    display(s);
                }
                peek(s);
            }
            break;

            case 4:{
                if(!isEmpty(s)){
                    printf("Stack is not empty");
                }
                else{
                    printf("Stack is empty");
                };
            }
            break;

            case 5:{
                if(!isEmpty(s)){
                    display(s);
                }
                stackSize(s);
            }
            break;

            case 6:{
                printf("Exiting program...");
            }
            break;

        }
    }
    free(s->arr);
    free(s);
    return 0;
}