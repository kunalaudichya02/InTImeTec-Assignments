#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
} node;

node * insertAtBegin(node *head, int n){

    node* ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Memory allocation failed");
        return head;
    }
    ptr->data = n;
    ptr->next = head;
    head = ptr;
    return head;
}
node * insertAtEnd(node *head, int n){
    node* ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Memory allocation failed");
        return head;
    }

    ptr->data = n;
    ptr->next = NULL;
    
    if(head == NULL){
        head = ptr;
        return head;
    }
    node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = ptr;

    return head;
}
node * insertAtIndex(node *head, int x, int n){
    node* ptr = (node*)malloc(sizeof(node));
    if(ptr == NULL){
        printf("Memory allocation failed");
        return head;
    }

    ptr->data = n;

    if (x == 1) { 
        ptr->next = head;
        head = ptr;
        return head;
    }

    node* temp = head;

    for(int i=1; i<x-1; i++){
        if (temp == NULL) {  
            printf("Invalid position\n");
            free(ptr);
            return head;
        }
        temp = temp->next;
    }
    if (temp->next == NULL){  
        printf("Invalid position\n");
        free(ptr);
        return head;
    }
    ptr->next = temp->next;
    temp->next = ptr;

    return head;
}
node * updateAtIndex(node *head, int x, int n){
    if (head == NULL) {
        printf("The list is empty\n");
        return head;
    }
    node* temp = head;

    if (x == 1) { 
        head->data = n;
        return head;
    }
    for(int i=1; i<x; i++){
        if (temp == NULL) {  
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    if(temp== NULL){
        printf("Invalid position\n");
        return head;
    }
    
    temp->data = n;

    return head;
}
node * deleteFirst(node *head){
    if (head == NULL) {
        printf("List is empty\n");
        return head; 
    }
    node *ptr = head;
    head = ptr->next;
    free(ptr);
    return head;
}
node * deleteLast (node *head){
    if (head == NULL) {
        printf("List is empty\n");
        return head; 
    }
    if (head->next == NULL) {
        free(head);
        return NULL; 
    }
    
    node *ptr = head;
    node *remove = ptr->next;
    while(remove->next != NULL ){
        ptr = ptr->next;
        remove = remove->next;
    }

    ptr->next = NULL;
    free(remove);
    return head;
}
node * deleteAtIndex(node *head, int x){
    if (head == NULL) {
        printf("List is empty\n");
        return head; 
    }
    if (x == 1){
        head = deleteFirst(head);
        return head;
    }
    node *temp = head;
    for(int i=1; i<x-1; i++){
        if (temp == NULL) {  
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }

    if(temp->next == NULL){
        printf("Invalid position\n");
        return head;
    }
    node *remove = temp->next;
    temp->next = remove->next;
    free(remove);
    return head;
}
node * display(node *head){
    if (head == NULL) {
        printf("List is empty\n");
        return head; 
    }
    node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return head;
}
int main(){
    node * head = NULL;
    int n;
    scanf("%d", &n);


    for(int i=1; i<=n; i++){
        int x;
        scanf("%d", &x);

        switch(x){
            case 1:{
                int a;
                scanf("%d", &a);
                head = insertAtEnd(head, a);
            }
            break;
            
            case 2:{
                int a;
                scanf("%d", &a);
                head = insertAtBegin(head, a);
            }
            break;

            case 3:{
                int a, b;
                scanf("%d %d", &a, &b);
                head = insertAtIndex(head, a, b);
            }
            break;

            case 4:
                head = display(head);
            break;

            case 5:{
                int a, b;
                scanf("%d %d", &a, &b);
                head = updateAtIndex(head, a, b);
            }
            break;

            case 6:
                head = deleteFirst(head);
            break;

            case 7:
                head = deleteLast(head);
            break;

            case 8:{
                int a;
                scanf("%d", &a);
                head = deleteAtIndex(head, a);
                display(head);
            }
            break;
        }
    }

    return 0;
}