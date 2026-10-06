#include <stdio.h>
#define MAX 4
int queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int value)
{
    if(rear==MAX-1)
    {
        printf("overflow\n");
        return;
    }
    if(front==-1)
    {
        front=0;
    }
    rear++;
    queue[rear]=value;
    printf("value inserted at position %d\n",rear+1);

}
void dequeue()
{
    if(front==-1||front>rear)
    {
        printf("underflow\n");
        return;
    }
    else{
        printf("%d is deleted\n",queue[front]);
        front++;
}
}
void display()
{
    if(front==-1||front>rear)
    {
        printf("underflow\n");
        return;
    }
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",queue[i]);
    }

}
void main()
{
    printf("enter 1 for enqueue/insert\nenter 2 to dequeue/delete\nenter 3 to display all elements\nenter 4 to exit\n");

    int choice=0;
    while(choice!=4){
        printf("enter choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            int num;
            printf("enter an element\n");
            scanf("%d",&num);
            enqueue(num);
            break;
    }
    case 2:
        dequeue();break;
    case 3:
        display();break;
    default:
        printf("Enter valid choice");
}
    }
}
