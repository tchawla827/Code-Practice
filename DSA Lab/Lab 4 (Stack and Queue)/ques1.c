//IIT2023150 Tavish Chawla
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct node {
    struct node * next;
    int data;
} node;

typedef struct {
    node * tos;
} stack;

void push(stack *s, int n)
{
    node *p = (node *)malloc(sizeof(node));
    p->data = n;
    p->next = s->tos;
    s->tos = p;

    printf("%d pushed to the stack successfully!\n", n);
}

int pop(stack *s)
{
    if (s->tos == NULL)
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    else
    {
        int t = s->tos->data;
        node *q = s->tos;
        s->tos = q->next;
        free(q);
        return t;
    }
}

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    else
    {
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
}

void primeDiv(int n, stack *s)
{
    for (int i = n; i >= 0; i--)
    {
        if (isPrime(i) == 1)
        {
            if (n % i == 0)
                push(s, i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    while (s->tos != NULL)
        printf("%d ", pop(s));
}

int main()
{
    int x;
    printf("Enter n : ");
    stack s;
    s.tos = NULL;

    scanf("%d", &x);
    primeDiv(x, &s);

    return 0;
}
