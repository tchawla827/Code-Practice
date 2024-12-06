/*node *sortedInsert(node *head, int *c, int coeff, int pow)
{

    if (*c == 0)
    {
        head->coeff = coeff;
        head->power = pow;
        (*c)++;
        head->next = NULL;
        return head;
    }
    else
    {

        node *p, *q, *r;
        p = head;
        q = NULL;

        while (p != NULL && pow > p->power)
        {
            q = p;
            p = p->next;
        }

        r = (node *)malloc(sizeof(node));
        r->coeff = coeff;
        r->power = pow;

        if (q == NULL)
        {

            r->next = head;
            head = r;
        }
        else
        {

            q->next = r;
            r->next = p;
        }

        (*c)++;
        return head;
    }
}*/