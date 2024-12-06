#include <iostream>
using namespace std;

class node
{
public:
    node *next;
    char data;
};



int Validate(string str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]!='{' && str[i]!='(' && str[i]!='[' && str[i]!='}' && str[i]!=')' && str[i]!=']')
        {
            return -1;
        }
    }
    return 1;
}
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
    }

    char pop()
    {

        if (tos->next == NULL)
        {
            char temp = tos->data;
            node *q = tos;
            tos = NULL;
            delete q;
            return temp;
        }
        else
        {
            char temp = tos->data;
            node *q = tos;
            tos = tos->next;
            delete q;

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

int Paranthesis(Stack *s, string str) {
    int flag = 1; // yes
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s->push(str[i]);
        } else {
            char c = s->pop();
            if ((str[i] == '}' && c != '{') || (str[i] == ']' && c != '[') || (str[i] == ')' && c != '(')) {
                flag = -1; // no
                break;
            }
        }
    }
    if (!s->isEmpty()) 
        flag = -1;
    return flag;
}

int main()
{
    int choice = -1;
    Stack s;
    do
    {
        cout << endl;
        cout << "0. Exit\n";
       
        cout<<"1. Paranthesis Matching\n";

        cout << "\nEnter Choice Number : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(1);
            break;
        
        
        case 1:
            string str;
            cout<<"Enter string : ";
            cin>>str;
            if(Validate(str)==-1)
            {
                cout<<"\nPlease enter a valid string, {}/()/[] only!\n";
            }
            else
            {
                int flag=Paranthesis(&s, str);
                if(flag==-1)
                {
                    cout<<"\nUnbalanced Paranthesis\n";
                }
                else
                {
                    cout<<"\nBalanced Paranthesis\n";
                }
            }
    } 
}while (choice != 0);
}
