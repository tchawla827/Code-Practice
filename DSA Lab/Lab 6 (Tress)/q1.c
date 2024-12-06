
#include<stdio.h>

struct nodeTree{
    struct nodeTree * left;
    int value;
    struct nodeTree * right;
};
typedef struct nodeTree nodeTree;

int main()
{
    nodeTree root;
    printf("Enter value : ");
    int x;
    scanf("%d",&x);
    root.value=x;
    root.left=root.right=NULL;
}

