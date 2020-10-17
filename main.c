#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define size 26
int L,U;
int rear,front;
int ch;
int q[size];
int rear=-1;
int front=-1;
char arr[26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91};
void insert_queue();
void delete_queue();
void display_queue();
void insert_queue()
{
    if((front==0)&&(rear==size-1))
    {
        printf("\nOverflow");
        rear=1;
        return;
    }
    else
        if (front<0)
    {
        front=0;
        rear=0;
        printf("\nInput the roll number:");
        scanf("%d",&ch);
        q[rear]=ch;
    }
    else
    {
        if(rear==size-1)
        {
            rear=0;
            printf("\nInput the roll number:");
            scanf("%d",&ch);
            q[rear]=ch;
        }
        else
        {
            rear++;
            printf("\nInput the roll number:");
            scanf("%d",&ch);
            q[rear]=ch;
        }
    }
}
    void delete_queue()
    {
        if (front<0)
        {
            printf("\nUnderflow");
            return;
        }
        ch=q[front];
        q[front]=NULL;
        printf("\nRecord deleted:",ch);
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else
            if(front==size-1)
        {
            front=0;
        }
        else
        {
            front++;
        }
    }
    void display_queue()
    {
        int i;
        if(front<0)
            return;
        if(rear>=front)
        {
            for(i=front;i<=rear;i++)
            {
                printf("\ni=%d ",i);
                printf("  Rno:%d",q[i]);
                printf("  Name:");
                printf("%c%c%c\\0",arr[i],arr[i+1],arr[i+2]);
            }
        }
        else
        {
            for(i=front;i<size;i++)
            {
                printf("\ni=%d ",i);
                printf("  Rno:%d",q[i]);
                printf("  Name:");
                printf("%c%c%c\\0",arr[i],arr[i+1],arr[i+2]);
            }
            for(i=0;i<=rear;i++)
            {
                printf("\ni=%d ",i);
                printf("  Rno:%d",q[i]);
                printf("  Name:");
                printf("%c%c%c\\0",arr[i],arr[i+1],arr[i+2]);
            }
        }
    }
    void main()
    {
        int k=0;
        char choice;
        do
        {
            printf("\nInsert->i Delete->d Quit->q:");
            printf("\nInput the choice:");
            do
            {
                choice=getchar();
                choice=tolower(choice);
            }while(strchr("idq",choice)==NULL);
            printf("Your choice is %c",choice);
            switch(choice)
            {
            case 'i':
                insert_queue();
                printf("\nQueue after inserting");
                display_queue();
                break;
            case 'd':
                delete_queue();
                printf("\nQueue content after deletion is as follows:\n");
                display_queue();
                break;
            case 'q':
                k=1;
            }
        }while(!k);
    }
