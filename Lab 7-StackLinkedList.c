#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *top = NULL;

void push(int n) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory failure\n");
        return;
    }
    newNode->data = n;
    newNode->next = top;
    top = newNode;
    printf("%d is pushed\n", n);
}

void pop() {
    if (top == NULL) {
        printf("Underflow\n");
        return;
    }
    Node *temp = top;
    top = top->next;
    printf("Deleted %d\n", temp->data);
    free(temp);
}

void display() {
    Node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty (underflow)\n");
        return;
    }
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int cas, ele;

    while (1) {
        printf("\nEnter 1 to push\n2 to pop\n3 to display\n4 to exit\n");
        scanf("%d", &cas);

        switch (cas) {
            case 1:
                printf("Enter an element to be pushed: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Enter 1-4 only\n");
        }
    }
}
