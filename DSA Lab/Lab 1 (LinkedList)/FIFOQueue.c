//IIT2023150
//Tavish Chawla
//Ques 3
#include<stdio.h>
#include<stdlib.h>

int count = 0;
typedef struct
{
    struct node *next;
    int data;
} node;

void display(node *head, int c)
{
    if(c==0)
    {
        printf("LIST IS EMPTY!");
    }
    else{
    node *q = head;
    for (int i = 0; i < c; i++)
    {
        printf("%d ", q->data);
        q = q->next;
    }}
}

node * insertAtFront(node * p,int x)
{
    node*head=(node*)malloc(sizeof(node));
    if(count==0)
    {
        head->data=x;
        head->next=NULL;
    }
    else{
    head->data=x;
    head->next=p;}
    count++;
    printf("INSERTED SUCCESSFULLY!\n");
    return head;
}

void deleteAtEnd(node *p)
{   
    if(count==0)
    {
        printf("CANNOT DELETE,LIST IS EMPTY!\n");
    }
    else if(p->next==NULL)
    {
        free(p);
        p=NULL;
        printf("DELETED SUCCESSFULLY!\n");
    }
    else
    {node *q=p->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    printf("DELETED SUCCESSFULLY!\n");}
    count--;
}

int main()
{
    node*head;
    int choice,x;

    do{printf("\n");
        printf("0.EXIT\n");
        printf("1.INSERT AT FRONT\n");
        printf("2.DELETE AT END\n");
        printf("3.DISPLAY ELEMENTS\n");
        
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&choice);
        printf("\n");

        switch(choice)
        {
            case 1: 
                printf("ENTER THE ELEMENT : ");
                scanf("%d",&x);
                head=insertAtFront(head,x);
                break;
            case 2:
                deleteAtEnd(head);
                
                break;
                
            case 3:
                printf("LIST : ");
                display(head,count);
                printf("\n");
                break;

            case 0: 
                printf("THANKYOU!\n");
                exit(1);
                break;
            
            default:
                printf("WRONG INPUT, TRY AGAIN ");
        }
    }while(choice!=0);
}