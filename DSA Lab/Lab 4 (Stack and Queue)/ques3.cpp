//IIT2023150 Tavish Chawla
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
            std::cout << "\nStack Underflow\n";
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
    else
    {
        return -1;
    }
}

char * inToPost(Stack *s, string c)
{
    int l;
    for( l=0;c[l]!='\0';l++)
    {
    }
    char * A=new char[l+1];
    int k=0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if ((c[i] >= 'A' && c[i] <= 'Z') || (c[i] >= 'a' && c[i] <= 'z'))
        {
            A[k++]= c[i];
        }
        else if (c[i] == '(')
        {
            s->push(c[i]);
        }
        else if (c[i] == ')')
        {
            while (s->tos != NULL && s->tos->data != '(')
            {
                A[k++]= s->pop();
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
                    A[k++]= s->pop();

                s->push(c[i]);
            }
        }
    }
    while (s->tos != NULL)
        A[k++]= s->pop();

        A[k++]='\0';
        return A;
}



void reverse(string *str)
{
    int l;
    for (l = 0; (*str)[l] != '\0'; l++)
    {
        if((*str)[l]=='(')
        (*str)[l]=')';
        else if((*str)[l]==')')
        (*str)[l]='(';
    }
    for (int i = 0; i < l / 2; i++)
    {
        char temp = (*str)[i];
        (*str)[i] = (*str)[l - 1 - i];
        (*str)[l - 1 - i] = temp;
    }

}


int main()
{
    int l;
    int choice = -1;
    string str;
    Stack s;
    char *A;
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
            for(l=0;str[l]!='\0';l++)
            {}
            
            reverse(&str);
            A=inToPost(&s, str);
            for(int i=l-1;i>=0;i--)
            {
                std::cout<<A[i];
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