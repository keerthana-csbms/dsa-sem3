#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;
void deletebeginning()
{
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    struct Node *temp=head;
    head=head->next;
    free(temp);
    printf("%d is deleted\n",temp->data);
}
void deleteEnd()
{
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    if(head->next==NULL)
    {
        deletebeginning();return;
    }
    struct Node *temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    printf("%d is deleted\n",temp->next->data);
    free(temp->next);
    temp->next=NULL;

}
void deleteElement(int value)
{
    if(head==NULL)
    {
        printf("empty list\n");
        return;
    }
    if(head->data==value)
    {
        deletebeginning();return;
    }
    struct Node *prev=head,*temp=head->next;
    while(temp!=NULL&&temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("element not found\n");

    }
    prev->next=temp->next;
    free(temp);
    printf("%d is deleted\n",temp->data);
}
void insertEnd(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}
void display() {
    struct Node *temp = head;
    if(head == NULL) {
        printf("List is empty \n");
        return;
    }
    printf("Linked list : ");
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void main()
{
     int choice, value, pos, n;

    printf("Enter no of nodes\n");
    scanf("%d", &n);

    printf("Enter the elements \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(value);
    }
    do {
        printf("\n1.delete BEGINNING\n2.delete element\n3.delete at END\n4.DISPLAY\n5.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1: {
                deletebeginning();
                break;
            }
            case 2: {
                printf("Enter value \n");
                scanf("%d", &value);
                deleteElement(value);
                break;
            }
            case 3: {
                deleteEnd();
                break;
            }
            case 4:
                display();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice Please choose a option between 1 and 5.\n");
        }
    } while(choice != 5);
}
