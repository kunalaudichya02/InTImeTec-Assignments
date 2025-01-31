#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int id;
    char severity[10];
    struct Node *next;
} node;


int priority(char * severity){

    if(!strcmp(severity, "Critical"))return 1;
    else if(!strcmp(severity, "Serious")) return 2;
    else return 3;
}

node *sortList(node *head, int n, char *severity)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        return NULL;
    }
    // newNode->severity = (char *)malloc(100 * sizeof(char));
    newNode->id = n;
    strcpy(newNode->severity, severity);
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    else
    {
        if(priority(newNode->severity) == 1){
            newNode->next = head;
            head = newNode;
        }
        else if(priority(newNode->severity) == 3){
            node* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        else{
            node* temp = head;
            while(priority(temp->next->severity) == 1){
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = temp->next;
        }
    }

    return head;
}


void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d %s\n", temp->id, temp->severity);
        temp = temp->next;
    }
}



int main()
{
    node *head = NULL;
    int n;
    scanf("%d", &n);

    while (n != 0)
    {

        int id;
        scanf("%d", &id);
        char severity[100];
        scanf("%[^\n]", severity);
        head = sortList(head, id, severity);
        n--;
        getchar();
    }
    printf("\n");
    display(head);

    return 0;
}