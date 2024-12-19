#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node* appendNode(struct Node* head,int data)
{
    struct Node* newNode = createNode(data);
    if(head == NULL)
    {
        return newNode;
    }
    struct Node* temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}
void searchByValue(struct Node* head,int value)
{
    struct Node* temp = head;
    int position =1,found = 0;
    while(temp!=NULL)
    {
        if(temp->data == value)
        {
            printf("Value %d found at position %d.\n",value,position);
            found = 1;
            break;
        }
        temp = temp->next;
        position++;
    }
    if(!found)
    {
        printf("Value %d not found in the list.\n",value);
    }
}
void searchByPosition(struct Node* head,int position)
{
    struct Node* temp = head;
    int currentPosition = 1;
    while(temp!=NULL)
    {
        if(currentPosition == position)
        {
            printf("Value at position %d is %d.\n",position,temp->data);
            return;
        }
        temp = temp->next;
        currentPosition++;
    }
    printf("Position %d is out of the range.\n",position);
}
int main()
{
    struct Node* head = NULL;
    int choice,data,value,position;
    printf("Linked List Search Operations:\n");
    do{
        printf("\n1.Add Node\n");
        printf("2.Search By Value\n");
        printf("3.Search By position\n");
        printf("4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter data to add:");
            scanf("%d",&data);
            head = appendNode(head,data);
            break;
        case 2:
            printf("Enter value to search:");
            scanf("%d",&value);
            searchByValue(head,value);
            break;
        case 3:
            printf("Enter the position to search:");
            scanf("%d",&position);
            searchByPosition(head,position);
            break;
        case 4:
            printf("Exiting program.\n");
            break;
            printf("Invalid choice!.\n");
        }
    }
    while(choice!=4);
    return 0;
}
