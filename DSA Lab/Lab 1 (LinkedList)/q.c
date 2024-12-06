#include <stdio.h>
#include <stdlib.h>

// Define the structure before using it in typedef
struct node {
    struct node *next;
    int coeff;
    int power;
};

int count1 = 0;
int count2 = 0;

typedef struct node node;

node *sortedinsert(node *head, int coeff, int pow, int *c)
{
    if ((*c) == 0) {
        node *p = (node *)malloc(sizeof(node));
        p->coeff = coeff;
        p->power = pow;
        p->next = NULL;
        (*c)++;
        return p;
    } else {
        int flag = -1;
        node *p = head;
        for (int i = 0; i < (*c); i++) {
            if (p->power == pow) {
                p->coeff += coeff;
                flag = 1;
                break;
            }
            p = p->next;
        }
        if (flag == -1) {
            p = head;
            node *r;
            node *q = (node *)malloc(sizeof(node));
            q->power = pow;
            q->coeff = coeff;
            while (pow > p->power) {
                r = p;
                p = p->next;
            }
            r->next = q;
            q->next = p;
            (*c)++;
        }
    }
}

void display(node *head, int *c)
{
    node *p = head;
    for (int i = 0; i < (*c); i++) {
        printf("%dx^%d + ", p->coeff, p->power);
        p = p->next;
    }
    printf("\n");
}

int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    head1 = sortedinsert(head1, 3, 5, &count1);
    display(head1, &count1);

    return 0;
}
