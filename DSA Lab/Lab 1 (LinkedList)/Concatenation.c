//IIT2023150
//Tavish Chawla
//Ques 1
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int count1 = 0;
int count2 = 0;

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


node *concatenate(node *head, node *head1)
{
    if (head == NULL)
    {
        return head1;
    }
    else if (head1 == NULL)
    {
        return head;
    }

    node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }

    p->next = head1;
    count2 = count + count1;
    return head;
}


int main()
{
    int x;
    int choice;
    node *head = NULL;
    node *head1 = NULL;
    node *head2 = NULL;
    do
    {
        printf("\n");
        printf("1.INSERT A NODE IN LIST 1\n");
        printf("2.INSERT A NODE IN LIST 2\n");
        printf("3.DISPLAY ALL ELEMENTS IN LIST 1\n");
        printf("4.DISPLAY ALL ELEMENTS IN LIST 2\n");
        printf("5.CONCATENATE\n");
        printf("6.DISPLAY CONCATENATED LIST\n");
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
            printf("ENTER INTEGER ELEMENT : ");
            scanf("%d", &x);
            if (count1 == 0)
            {
                head1 = createnode(x, head1, &count1);
            }
            else
            {
                createnode(x, head1, &count1);
            }
            printf("NODE CREATED SUCCESSFULLY!\n");
            break;
        case 3:
            printf("LIST 1 : ");
            display(head, count);
            printf("\n");
            break;
        case 4:
            printf("LIST 2 : ");
            display(head1, count1);
            printf("\n");
            break;
        case 5:
            head2 = concatenate(head, head1);
            printf("CONCATENATED SUCCESSFULLY!\n");
            break;
        case 6:
            printf("CONCATENATED LIST : ");
            display(head2, count2);
            printf("\n");
            break;
        }
    } while (choice != -1);
}
