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
    int count = 0;
    void push(char x)
    {
        node *p = new node;
        p->data = x;

        p->next = tos;
        tos = p;
        count++;
    }

    char pop()
    {

        if (tos->next == NULL)
        {
            char temp = tos->data;
            node *q = tos;
            tos = NULL;
            delete q;
            count--;
            return temp;
        }
        else
        {
            char temp = tos->data;
            node *q = tos;
            tos = tos->next;
            delete q;
            count--;
            return temp;
        }
    }
    int isEmpty()
    {
        if (tos == NULL)
        {
            return -1;
        }
        return 0;
    }
};

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(string str, Stack *s)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            cout << str[i];
        }
        else if (str[i] == '(')
        {
            s->push(str[i]);
        }
        else if (str[i] == ')')
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
            while (s->tos != NULL && precedence(str[i]) <= precedence(s->tos->data))
            {
                cout << s->pop();
            }
            s->push(str[i]);
        }
    }

    while (s->tos != NULL)
    {
        cout << s->pop();
    }
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
            infixToPostfix(str, &s);
            cout << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}
