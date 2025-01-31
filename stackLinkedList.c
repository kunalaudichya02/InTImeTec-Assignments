#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
} node;

typedef struct Stack{
    struct Node* top;
    int size;
} stack;

void stackInit(stack * s){
    s->top = NULL;
    s->size = 0;
}

int isEmpty(stack *s){
    if(s->top == NULL){
        return 1;
    }
    else{
        return 0; 
    }
}
void push(stack *s, int value){
    node* newNode = (node*)malloc(sizeof(node));
    if(newNode == NULL){
        printf("Stack Overflow\n");
        return ;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow.\n");
    }
    else{
        node* temp = s->top;
        int data = temp->data;
        s->top = s->top->next;
        free(temp);
        s->size--;
        return data;
    }
}
void peek(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        printf("The top of the stack is: %d\n", s->top->data);
    }
}

void stackSize(stack *s){
    if(isEmpty(s)){
        printf("Size of the stack is 0.\n");
    }
    else{
        printf("Size of the stack is %d\n", s->size);
    }
}

void display(stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }
    else{
        node* temp = s->top;
        printf("Stack: ");
        while(temp != NULL){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(){
    stack* s = (stack*)malloc(sizeof(stack));
        if(s==NULL){
        printf("Memory allocation failed\n");
        return -1;
    }
    stackInit(s);
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
                if(!isEmpty(s)){
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
    while(s->top != NULL){
        pop(s);
    }
    free(s);
    return 0;
}