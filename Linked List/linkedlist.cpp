#include<stdio.h>
#include<stdlib.h>
using namespace std;

int count=0;
int count1=0;

struct Node {
    struct Node* next;
    int data;
};

struct Node* createNode(int x, struct Node* head) {
    struct Node* q;
    
    if (count == 0) {
        struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = x;
        new_node->next = NULL;
        count++;
        return new_node;
    } else {
        q = head;
        for (int i = 0; i < count - 1; i++) {
            q = q->next;
        }
        q->next = (struct Node*)malloc(sizeof(struct Node));
        q = q->next;
        q->data = x;
        q->next = NULL;
        count++;
        return 0;
    }
}

struct Node* createNode1(int x, struct Node* head) {
    struct Node* q;

    if (head == NULL) {
        struct Node* new_node = new Node;
        new_node->data = x;
        new_node->next = NULL;
        return new_node;
    } else {
        q = head;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = new Node;
        q = q->next;
        q->data = x;
        q->next = NULL;
        return head;
    }
}


void Display(struct Node* head) {
    struct Node* q = head;
    while (q != NULL) {
        printf("%d ", q->data);
        q = q->next;
    }
}

void concatenate(Node *head, Node *head1)
{
    struct Node *q=head;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=head1;
}

void sortedinsert(Node *h,int x)
{
   
    struct Node *q=h;
    while(q->next->data<x)
    {
        q=q->next;
    }
    struct  Node* p=q->next;
    q->next=(Node *)malloc(sizeof(Node));
    q->next->data=x;
    q->next->next=p;

}

int main() {
    struct Node* head = NULL;
    struct Node* head1=NULL;
    int i;
    do{
        printf("1. CREATE A NEW NODE IN LIST 1 \n");
        printf("2. DISPLAY ALL ELEMENTS IN LIST 1 \n");
        printf("3. CREATE A NEW NODE IN LIST 2 \n");
        printf("4. DISPLAY ALL ELEMENTS IN LIST 2 \n");  
        printf("5. CONCATENATE\n");
        printf("6. SORTED INSERT IN LIST 1\n");
        printf("7. SORTED INSERT IN LIST 2\n");
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&i);

        switch (i)
        {
            case 1: int x;
                printf("ENTER AN INTEGER : ");
                scanf("%d",&x);
                if(count==0)
                {head=createNode(x,head);}
                else
                createNode(x,head);
                printf("NODE CREATED SUCCESSFULLY ! \n");
                break;
            case 2: Display(head);
                    printf("\n");
                    break;
            case 3: printf("ENTER AN INTEGER : ");
                    scanf("%d",&x);
                    if(count1==0)
                    {head1=createNode1(x,head1);}
                    else
                    createNode1(x,head1);
                    printf("NODE CREATED SUCCESSFULLY ! \n");
                    break;
            case 4: Display(head1);
                    printf("\n");
                    break;
            case 5: concatenate(head,head1);
                    printf("SUCCESSFUL!\n");
                    break;

            case 6: printf("ENTER ELEMENT : ");
                    scanf("%d",&x);
                    
                    sortedinsert(head,x);
                printf("SUCCESSFUL!\n");
                break;
            case 7: printf("ENTER ELEMENT : ");
                    scanf("%d",&x);
                sortedinsert(head1,x);
                printf("SUCCESSFUL!\n");
                break;
            

        }
    }while(i!=-1);

    return 0;
}
