#include<stdio.h>
#include<stdlib.h>

#define TABLE_SIZE 10

typedef struct node{
    int key;
    int value;
    struct node *next;
}node;

node *createNode(int key, int value){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = NULL;
    newNode->key = key;
    newNode->value = value;

    return newNode;
}

node *createList(node *head, int key, int value){
    node* newNode = createNode(key, value);
    if(newNode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    if(head == NULL){
        head = newNode;
        return head;
    }

    node *ptr = head;
    while(ptr != NULL){
        if(ptr->key == key){
            ptr->value = value;
            free(newNode);
            return head;
        }
        if(ptr->next == NULL){
            break;
        }
        ptr = ptr->next;
    }
    ptr->next = newNode;
    return head;
}

node *hashMap[TABLE_SIZE] = {NULL};

int hash(int key){
    return key%TABLE_SIZE;
}

void insertInHashmap(int key, int value){
    int index = hash(key);
    hashMap[index] = createList(hashMap[index], key, value);
    return;
}

int search(int key){
    int index = hash(key);
    node *ptr = hashMap[index];
    while(ptr!= NULL){
        if(ptr->key == key){
            return ptr->value;
        }
        ptr = ptr->next;
    }

    return -1;
}

void display(){
    
    printf("\n");
    printf("(index)\t (key-value pair)\n");
    for(int i=0;i<TABLE_SIZE;i++){
        printf("%d : ", i);
        node *ptr = hashMap[i];
        while(ptr!= NULL){
            if(ptr->next == NULL){
                printf("(%d, %d)", ptr->key, ptr->value);
            }
            else{
                printf("(%d, %d) -> ", ptr->key, ptr->value);
            }
            ptr = ptr->next;
        }
        printf("\n");
    }
    return;
}

void deleteFromHashmap(int key){
    int index = hash(key);
    if(hashMap[index]==NULL) return;

    node *ptr = hashMap[index];
    if(hashMap[index]->key == key){
        if(hashMap[index]->next !=NULL) {
            hashMap[index] = hashMap[index]->next;
        }
        else{
             hashMap[index] = NULL;
        }
        return;
    }

    ptr = hashMap[index];
    while(ptr!= NULL && ptr->next!= NULL){
        if(ptr->next->key == key){
            ptr->next = ptr->next->next;
            return;
        }
        ptr = ptr->next;
    }
    return;
}

int main(){
    int count;
    printf("Enter number of operations to perform: ");
    scanf("%d", &count);

    while(count != 0){
        int op;
        printf("\n1. Insert a key-value pair.\n2. Search the value.\n3. Delete a key-value pair.\n4. Display all key-value pairs\n");
        printf("Enter operation: ");
        scanf("%d", &op);

        switch(op){
            case 1:{
                int key;
                int value;
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                insertInHashmap(key, value);
                op--;
            }
            break;
            case 2:{
                int key;
                printf("Enter key to be searched: ");
                scanf("%d", &key);
                int value = search(key);
                printf("value is : %d", value);
                op--;
            }
            break;
            case 3:{
                int key;
                printf("Enter key to be deleted: ");
                scanf("%d", &key);
                deleteFromHashmap(key);
                op--;
            }
            break;
            case 4:{
                display();
                op--;
            }
            break;
        }
    }
}