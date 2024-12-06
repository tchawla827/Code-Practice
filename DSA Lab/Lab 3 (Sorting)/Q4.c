
#include <stdlib.h>
#include <stdio.h>

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

int flag=-1;
node * LinearSearch(int key, node *head)
{
    if (count==0)
    {
        printf("List is empty, Cant Search!\n");
    }
    else
    {
        node *p=head;
        node *q;
        do{

            if(p->data==key)
            {  flag=0;
                return q;}
            q=p;
            p=p->next;
        }while(p!=NULL);
    }
}

node *connect(node *head, node *q)
{
    node *r=q->next;
    node *s=r->next;
    q->next=s;
    r->next=head;
    return r;
}


int main()
{
    int x;
    int choice;
    node *head = NULL;
    
    do
    {
        printf("\n");
        printf("1.INSERT A NODE IN LIST \n");

        printf("2.DISPLAY ALL ELEMENTS IN LIST \n");
        printf("3.Linear Search the key\n");
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
            printf("LIST 1 : ");
            display(head, count);
            printf("\n");
            break;
        case 3:
            printf("ENTER THE KEY : ");
            int key;
            scanf("%d",&key);
            node *q=LinearSearch(key,head);
            if(flag==0)
            {
                head=connect(head,q);
                printf("Successful!\n");
            }
            else{
                printf("Key not found!\n");
            }
        }
    } while (choice != -1);
}