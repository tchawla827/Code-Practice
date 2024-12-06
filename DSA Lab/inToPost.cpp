#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    char data;
};

class Stack
{
public:
    node *tos = NULL;

    void push(char x)
    {
        if (tos == NULL)
        {
            node *p = new node;
            p->data = x;
            p->next = NULL;
            tos = p;
        }
        else
        {
            node *p = new node;
            p->data = x;
            p->next = tos;
            tos = p;
        }
    }

    char pop()
    {
        if (tos == NULL)
        {
            cout << "\nStack Underflow\n";
            return -1;
        }
        else
        {
            int temp = tos->data;
            node *q = tos;
            tos = tos->next;
            delete q;
            return temp;
        }
    }
};

int precedence(char c)
{
    if (c == '+' || c == '-')
    {
        return 0;
    }
    else if (c == '*' || c == '/')
    {
        return 1;
    }
    else if(c=='^')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

int inToPost(Stack *s, string c)
{
    for (int i = 0; c[i] != '\0'; i++)
    {
        if ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))
        {
            cout << c[i];
        }
        else if (c[i] == '(')
        {
            s->push(c[i]);
        }
        else if (c[i] == ')')
        {
            while (s->tos != NULL && s->tos->data != '(')
            {
                cout << s->pop();
            }
            if (s->tos != NULL && s->tos->data == '(')
            {
                s->pop();
            }
        }
        else
        {
            if (s->tos == NULL || precedence(c[i]) > precedence(s->tos->data))
            {
                s->push(c[i]);
            }
            else
            {
                while (s->tos != NULL && precedence(s->tos->data) >= precedence(c[i]))
                    cout << s->pop();

                s->push(c[i]);
            }
        }
    }
    while (s->tos != NULL)
        cout << s->pop();
}

int main()
{
    int choice = -1;
    string str;
    Stack s;
    do
    {
        cout << endl;
        cout << "0. Exit\n";
        cout << "1. Infix to Postfix\n";

        cout << "\nEnter Choice Number : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:

            cout << "Input String : ";
            cin >> str;
            inToPost(&s, str);
            cout << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}
