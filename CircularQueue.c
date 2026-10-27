#include <stdio.h>
#define MAX 3
int circ_queue[MAX];
int front=-1;
int rear=-1;
void enqueue(int n)
{
    if((rear+1)%MAX==front)
    {
    printf("overflow\n");
    return;
    }
    else if(front==-1)
    {
        front=rear=0;
    }
    else
    {
        rear=(rear+1)%MAX;

    }
    circ_queue[rear]=n;
}
void dequeue()
{

    if(front==-1)
    {
    printf("underflow\n");
    return;
    }
       printf("%d is deleted\n",circ_queue[front]);
    if(front==rear)
    {
        front=rear=-1;
    }
    else
    {
        front=(front+1)%MAX;
    }
}
void display()
{
    for(int i=front;i<=rear;i++)
    {
        printf("%d\n",circ_queue[i]);
    }

}
void main()
{


    while(1)
    {
         printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        int num;
        scanf("%d",&num);
        switch(num)
        {
        case 1:
            {
                int a;
                printf("enter num to insert\n");
                scanf("%d",&a);
                enqueue(a);
                break;
            }
        case 2:
            {
                dequeue();break;
            }
        case 3:
            display();break;
        case 4:
            break;
        default:
            printf("Enter 1-4 valid choice only\n");
        }
    }
}

