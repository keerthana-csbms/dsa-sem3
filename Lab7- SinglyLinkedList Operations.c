#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *createlist(Node *head, int n) {
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory failure\n");
            return head;
        }
        printf("Enter element %d: ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    return head;
}

void display(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node *concat(Node *head1, Node *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

Node *reverse(Node *head) {
    Node *current = head;
    Node *prev = NULL;
    Node *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

Node *sort(Node *head) {
    if (head == NULL) return head;

    Node *temp = NULL;
    Node *current = NULL;
    int swap;

    for (temp = head; temp->next != NULL; temp = temp->next) {
        for (current = temp->next; current != NULL; current = current->next) {
            if (temp->data > current->data) {
                swap = temp->data;
                temp->data = current->data;
                current->data = swap;
            }
        }
    }
    return head;
}

int main() {
    int cas, num;
    Node *head1 = NULL;
    Node *head2 = NULL;

    printf("Enter no of elements in linked list: ");
    scanf("%d", &num);
    head1 = createlist(head1, num);
    display(head1);

    while (1) {
        printf("\nEnter:\n1 to concat\n2 to reverse\n3 to sort\n4 to exit\nChoice: ");
        scanf("%d", &cas);

        switch (cas) {
            case 1:
                printf("Enter no of elements in linked list 2: ");
                scanf("%d", &num);
                head2 = NULL; // Reset head2 before creating a new list
                head2 = createlist(head2, num);
                head1 = concat(head1, head2);
                display(head1);
                break;
            case 2:
                head1 = reverse(head1);
                display(head1);
                break;
            case 3:
                head1 = sort(head1);
                display(head1);
                break;
            case 4:
                return 0;
            default:
                printf("Enter 1-4 only\n");
        }
    }
}
