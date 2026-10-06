#include <stdio.h>
#define SIZE 5

int st[SIZE];
int top = -1;

void push()
{
    int val;
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element: ");
        scanf("%d", &val);

        top++;
        st[top] = val;
        printf("%d pushed into stack\n", val);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("%d popped from stack\n", st[top]);
        top--;
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", st[i]);
    }
}

int main()
{
    int opt;

    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt)
        {
            case 1: push();    break;
            case 2: pop();     break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid Choice\n");
        }
    }

    return 0;
}
