#include <iostream>
#include<string>
#include<string.h>
using namespace std;

void reverse(string *str) {
    int length = 0;
    // Calculate the length of the string
    for (int i = 0; (*str)[i] != '\0'; i++) {
        length++;
    }

    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = (*str)[i];
        (*str)[i] = (*str)[length - 1 - i];
        (*str)[length - 1 - i] = temp;
    }

    // Swap '(' and ')' characters
    for (int i = 0; i < length; i++) {
        if ((*str)[i] == '(') {
            (*str)[i] = ')';
        } else if ((*str)[i] == ')') {
            (*str)[i] = '(';
        }
    }
}



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

char * infixToPostfix(string str, Stack *s)
{
    int length=0;
    for(int i=0;str[i]!='\0';i++)
    length++;
    int k=0;
    char * c=new char[length+1];
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            c[k++]= str[i];
        }
        else if (str[i] == '(')
        {
            s->push(str[i]);
        }
        else if (str[i] == ')')
        {
            while (s->tos != NULL && s->tos->data != '(')
            {
                c[k++]= s->pop();
            }
            if (s->tos != NULL && s->tos->data == '(')
            {
                c[k++]=s->pop();
            }
        }
        else
        {
            while (s->tos != NULL && precedence(str[i]) < precedence(s->tos->data))
            {
                c[k++]=s->pop();
            }
            s->push(str[i]);
        }
        c[length]='\0';
    }

    while (s->tos != NULL)
    {
        c[k++]= s->pop();
    }
    return c;
}

int main()
{
    int l=0;
    char * c;
    string res;
    int choice = -1;
    string str;
    Stack s;
    do
    {

        std::cout << endl;
        std::cout << "0. Exit\n";
        std::cout << "1. Infix to Prefix\n";

        std::cout << "\nEnter Choice Number : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            
            std::cout << "Input String : ";
            cin >> str;
            reverse(&str);
            c=infixToPostfix(str, &s);
            for(int i=0;c[i]!='\0';i++)
            {
                l++;
            }
            for(int i=l-1;i>=0;i--)
            {
                cout<<c[i];
            }

            
            

            std::cout << endl;
            break;
        default:
            std::cout << "Invalid choice. Please enter a valid option.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}
