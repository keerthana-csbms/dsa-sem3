#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue(int ele) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory failure\n");
        return;
    }
    newNode->data = ele;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    }
    Node *temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    printf("Deleted %d\n", temp->data);
    free(temp);
}

void peek() {
    if (front == NULL) {
        printf("Underflow\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

void display() {
    if (front == NULL) {
        printf("Underflow\n");
    } else {
        Node *temp = front;
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int cas, ele;
    while (1) {
        printf("\nEnter:\n1 to enqueue\n2 to dequeue\n3 to display\n4 to peek\n5 to exit\nChoice: ");
        scanf("%d", &cas);

        switch (cas) {
            case 1:
                printf("Enter an element to be enqueued: ");
                scanf("%d", &ele);
                enqueue(ele);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                return 0;
            default:
                printf("Enter 1-5 only\n");
        }
    }
}
