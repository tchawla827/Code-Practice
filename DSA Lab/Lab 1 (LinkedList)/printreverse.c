//IIT2023150
//Tavish Chawla
//Ques 1
#include <stdio.h>
#include <stdlib.h>
int count = 0;

typedef struct
{
    struct node *next;
    
    int data;
} node;

void display(node *head, int c)
{
    node *q = head;
    for (int i = 0; i < c; i++)
    {

        printf("%d ", q->data);
        q = q->next;
    }
}

void revdisp(node * head,node *p )
{
    if(p->next!=NULL)
    {
        revdisp(head,p->next);
    }
    printf("%d ",p->data);
}

node *createnode(int x, node *head, int *c)
{
    if (*c == 0)
    {
        node *p = (node *)malloc(sizeof(node));
        p->next = NULL;
        p->data = x;
        (*c)++;
        return p;
    }
    else
    {
        node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        node *q = (node *)malloc(sizeof(node));
        p->next = q;
        q->next = NULL;
        q->data = x;
        (*c)++;
        return q;
    }
}




int main()
{
    int x;
    int choice;
    node *head = NULL;

    do{
        printf("\n");
        printf("1.INSERT A NODE IN LIST\n");
        printf("2.DISPLAY ALL ELEMENTS IN LIST\n");
        printf("3.DISPLAY ALL ELEMENTS IN REVERSE\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("ENTER INTEGER ELEMENT : ");
            scanf("%d", &x);
            if (count == 0)
            {
                head = createnode(x, head, &count);
            }
            else
            {
                createnode(x, head, &count);
            }
            printf("NODE CREATED SUCCESSFULLY!\n");
            break;
        case 2:
            printf("LIST : ");
            display(head, count);
            printf("\n");
            break;
        case 3:
            printf("REVERSE LIST : ");
            revdisp(head,head);
            break;

        default: printf("WRONG INPUT\n");
                 break;
        }
    }while(choice!=0);
}