//IIT2023150 Tavish Chawla
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    char data;
} Node;

typedef struct Stack {
    Node *tos;
    int count;
} Stack;

int Validate(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '{' && str[i] != '(' && str[i] != '[' && str[i] != '}' && str[i] != ')' && str[i] != ']') {
            return -1;
        }
    }
    return 1;
}

void push(Stack *s, char x) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = s->tos;
    s->tos = p;
}

char pop(Stack *s) {
    if (s->tos == NULL) {
        fprintf(stderr, "Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    char temp = s->tos->data;
    Node *q = s->tos;
    s->tos = s->tos->next;
    free(q);

    return temp;
}

int isEmpty(Stack *s) {
    return s->tos == NULL ? -1 : 0;
}

int Paranthesis(Stack *s, const char *str) {
    int flag = 1; // yes
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '{' || str[i] == '[' || str[i] == '(') {
            push(s, str[i]);
        } else {
            char c = pop(s);
            if ((str[i] == '}' && c != '{') || (str[i] == ']' && c != '[') || (str[i] == ')' && c != '(')) {
                flag = -1; // no
                break;
            }
        }
    }
    if (!isEmpty(s))
        flag = -1;
    return flag;
}

int main() {
    int choice = -1;
    Stack s;
    s.tos = NULL;
    s.count = 0;

    do {
        printf("\n");
        printf("0. Exit\n");
        printf("1. Paranthesis Matching\n");

        printf("\nEnter Choice Number : ");
        scanf("%d", &choice);

        switch (choice) {
        case 0:
            exit(1);
            break;

        case 1: {
            char str[100];
            printf("Enter string : ");
            scanf("%s", str);
            if (Validate(str) == -1) {
                printf("\nPlease enter a valid string, {}/()/[] only!\n");
            } else {
                int flag = Paranthesis(&s, str);
                if (flag == -1) {
                    printf("\nUnbalanced Paranthesis\n");
                } else {
                    printf("\nBalanced Paranthesis\n");
                }
            }
            break;
        }
        } // switch
    } while (choice != 0);

    return 0;
}
