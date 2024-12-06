//IIT2023150
//Tavish Chawla
//Ques 2

#include <stdio.h>
#include <stdlib.h>

typedef struct node
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
    printf("\n");
}

int count = 0;

node *SortedInsert(int x, node *head)
{
    node *p, *q, *r;
    p = head;

    r = (node *)malloc(sizeof(node));
    r->data = x;
    r->next = NULL;

    if (count == 0 || x < head->data)
    {
        r->next = head;
        head = r;
        count++;
    }
    else
    {
        while (p != NULL && p->data < x)
        {
            q = p;
            p = p->next;
        }
        q->next = r;
        r->next = p;
        count++;  
    }

    return head;
}


int main()
{
    node *head = NULL;
    int x, choice;
    do
    {
        printf("\n");
        printf("0. Exit The Program\n");
        printf("1. Sorted Insert\n");
        printf("2. Display\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice)
        {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            head = SortedInsert(x, head);
            printf("Element Inserted Successfully!\n");
            break;
        case 2:
            display(head, count);
            break;
        case 0:
            printf("Thankyou!\n");
            exit(1);
            break;
        default:
            printf("Wrong Choice, Choose Again\n");
        }
    } while (choice != 0);

    return 0;
}
