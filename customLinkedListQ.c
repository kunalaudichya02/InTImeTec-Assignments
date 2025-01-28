/*
Problem:
Create two singly linked lists by taking user input
Sort both linked lists in ascending order.
Merge the two sorted lists into a single list such that nodes are taken alternately from each list.
If one list is exhausted, append the remaining nodes of the other list.


Time and Space complexity analysis:
Time complexity:
we are finding middle node of each list 
so the time complexity of this operation is O(n)
we are splitting the list into two halves each until both of the halves have one node each
so the time complexity for this operation is O(logn)
After this operation we are doing merging of two sorted linked list which will have time complexity of O(n)
so the combined time complexity will be O(nlogn) + O(n)

Space complexity:
While dividing the halves, the space required will be O(logn)
and while merging we are not using any additional space so this operation will cost O(1)
So the space complexity of this problem will be O(logn)
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
} node;

node* createNode(int value){
    node* newNode = (node *)malloc(sizeof(node));
    if(newNode == NULL){
        return NULL;
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

node* createList(int value, node* head){
    node * newNode = createNode(value);
    if(newNode == NULL){
        return NULL ;
    }
    if(head == NULL){
        head = newNode;
    }
    else{
        node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    return head;
}

void displayList(node* head){
    if(head == NULL){
        return;
    }
    node * temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

node* findMiddle(node* head){

    node* slow = head;
    node* fast = head->next;

    while(fast!= NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
node* merge(node* left, node* right){
    node* dummyNode = createNode(-1);
    node* t1 = left;
    node* t2 = right;
    node * temp = dummyNode;
    while(t1!= NULL && t2 != NULL){
        if(t1->data < t2->data){
            temp->next = t1;
            temp = t1;
            t1 = t1->next;
        }
        else{
            temp->next = t2;
            temp = t2;
            t2 = t2->next;
        }
    }
    if(t1 != NULL){
        temp->next = t1;
    }
    else{
        temp->next = t2;
    }
    return dummyNode->next;
}
node* mergeSort(node* head){
    if(head == NULL || head->next == NULL) return head;
    node* middle = findMiddle(head);
    node* left = head;
    node* right = middle->next;
    middle->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
}

node* mergeTwoSortedList(node* left, node* right){
    node* dummyNode = createNode(-1);
    node* t1 = left;
    node* t2 = right;
    node* temp = dummyNode;
    while(t1 != NULL && t2 != NULL){
        temp->next = t1;
        temp = t1;
        t1 = t1->next;

        temp->next = t2;
        temp = t2;
        t2 = t2->next;
    }
    if(t1 != NULL){
        temp->next = t1;
    }
    else{
        temp->next = t2;
    }
    return dummyNode->next;
}
int main() {
    node *head1 = NULL;
    node *head2 = NULL;
    printf("Enter first list: ");
    int n;
    while(scanf("%d", &n) == 1){
        head1 = createList(n, head1);
        if(getchar() == '\n') break;
    }
    printf("Enter second list: ");
    int m;
    while(scanf("%d", &n) == 1){
        head2 = createList(n, head2);
        if(getchar() == '\n') break;
    }
    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    printf("First Sorted list: \n");
    displayList(head1);
    printf("\nSecond Sorted list: \n");
    displayList(head2);
    
    node * head = mergeTwoSortedList(head1, head2);
    printf("\nMerged list: \n");
    displayList(head);
    return 0;
}
