#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
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

void insertPosition(int value, int pos) {
    struct Node *newNode, *temp;
    int i;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for(i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if(temp == NULL) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
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

int main() {
    int choice, value, pos, n;

    printf("Enter no of nodes\n");
    scanf("%d", &n);

    printf("Enter the elements \n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &value);
        insertEnd(value);
    }

    do {
        printf("\n1.INSERT BEGINNING\n2.INSERT AT POSITION\n3.INSERT END\n4.DISPLAY\n5.EXIT\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice) {
            case 1: {
                printf("Enter value\n");
                scanf("%d", &value);
                insertBeginning(value);
                break;
            }
            case 2: {
                printf("Enter value and position \n");
                scanf("%d %d", &value, &pos);
                insertPosition(value, pos);
                break;
            }
            case 3: {
                printf("Enter value\n");
                scanf("%d", &value);
                insertEnd(value);
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

    return 0;
}
