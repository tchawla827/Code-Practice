//IIT2023150
//TAVISH CHAWLA
//POLYNOMIAL 

#include <stdio.h>
#include <stdlib.h>

int count1 = 0;
int count2 = 0;
int count3 = 0;

struct node
{
    struct node *next;
    int coeff;
    int power;
};

typedef struct node node;

node *sortedinsert(node *head, int coeff, int pow, int *c)
{
    if ((*c) == 0)
    {
        node *p = (node *)malloc(sizeof(node));
        p->coeff = coeff;
        p->power = pow;
        p->next = NULL;
        (*c)++;
        return p;
    }
    else
    {
        int flag = -1;
        node *p = head;
        node *prev = NULL;

        while (p != NULL)
        {
            if (p->power == pow)
            {
                p->coeff += coeff;
                flag = 1;
                break;
            }
            else if (p->power > pow)
            {
                break;
            }
            prev = p;
            p = p->next;
        }

        if (flag == -1)
        {
            node *q = (node *)malloc(sizeof(node));
            q->power = pow;
            q->coeff = coeff;
            q->next = p;
            prev->next = q;
            (*c)++;
        }

        return head;
    }
}

int containsPower(node *head, int pow)
{

    while (head != NULL)
    {
        if (head->power == pow)
        {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

node *add(node *head1, node *head2, int *c1, int *c2)
{
    if (head1 == NULL && head2 == NULL)
    {
        printf("Both polynomials are empty.\n");
        return NULL;
    }
    else if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    node *p3 = NULL;
    node *p1 = head1;
    int flag = -1;

    while (p1 != NULL)
    {
        node *p2 = head2;
        while (p2 != NULL)
        {
            if (p1->power == p2->power)
            {
                p3 = sortedinsert(p3, p1->coeff + p2->coeff, p1->power, &count3);
                flag = 1;
                break;
            }
            p2 = p2->next;
        }

        if (flag == -1)
        {
            p3 = sortedinsert(p3, p1->coeff, p1->power, &count3);
        }

        p1 = p1->next;
        flag = -1;
    }

    node *remainingTerms = head2;
    while (remainingTerms != NULL)
    {

        if (!containsPower(p3, remainingTerms->power))
        {
            p3 = sortedinsert(p3, remainingTerms->coeff, remainingTerms->power, &count3);
        }
        remainingTerms = remainingTerms->next;
    }

    return p3;
}

void display(node *head, int *c)
{
    node *p = head;
    for (int i = 0; i < (*c) - 1; i++)
    {
        printf("%dx^%d + ", p->coeff, p->power);
        p = p->next;
    }
    for (int i = 0; i < (*c); i++)
    {
        if (i == (*c) - 1)
            printf("%dx^%d ", p->coeff, p->power);
    }
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    node *head3 = NULL;
    int choice = -1, coeff = -1, pow = -1;

    do
    {
        printf("\n\n");
        printf("0.EXIT\n");
        printf("1.ADD IN POLYNOMIAL 1\n");
        printf("2.ADD IN POLYNOMIAL 2\n");
        printf("3.DISPLAY POLYNOMIAL 1\n");
        printf("4.DISPLAY POLYNOMIAL 2\n");
        printf("5.ADD BOTH POLYNOMIAL\n");
        printf("6.DISPLAY ADDED POLYNOMIAL\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 0:
            printf("Thank you!\n");
            exit(1);
            break;
        case 1:
            printf("Enter Coefficient : ");
            scanf("%d", &coeff);
            printf("Enter Power : ");
            scanf("%d", &pow);
            if (count1 == 0)
                head1 = sortedinsert(head1, coeff, pow, &count1);
            else
                sortedinsert(head1, coeff, pow, &count1);
            printf("Successful!\n");
            break;
        case 2:
            printf("Enter Coefficient : ");
            scanf("%d", &coeff);
            printf("Enter Power : ");
            scanf("%d", &pow);
            if (count2 == 0)
                head2 = sortedinsert(head2, coeff, pow, &count2);
            else
                sortedinsert(head2, coeff, pow, &count2);
            printf("Successful!\n");
            break;
        case 3:
            printf("Polynomial 1 : ");
            display(head1, &count1);
            break;
        case 4:
            printf("Polynomial 2 : ");
            display(head2, &count2);
            break;
        case 5:
            if (count3 == 0)
                head3 = add(head1, head2, &count1, &count2);
            else
                add(head1, head2, &count1, &count2);
            printf("Added Successfully!\n");
            break;
        case 6:
            printf("Polynomial 1 + Polynomial 2 : ");
            display(head3, &count3);
            break;
        }

    } while (choice != 0);

    return 0;
}
