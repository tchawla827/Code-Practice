
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int flag = -1;

struct data
{
    int roll;
    char name[20];
    char branch[5];
    float cg;
};

typedef struct data data;

void addStudent(data *p)
{
    char nam[20];
    printf("ENTER NAME OF STUDENT : ");
    scanf("%s", nam);
    for (int i = 0; nam[i] != '\0'; i++)
    {
        p[count].name[i] = nam[i];
    }

    int rol;
    printf("ENTER ROLL NO. OF STUDENT : ");
    scanf("%d", &rol);
    p[count].roll = rol;

    char branc[5];
    printf("ENTER BRANCH OF STUDENT : ");
    scanf("%s", branc);
    for (int i = 0; branc[i] != '\0'; i++)
    {
        p[count].branch[i] = branc[i];
    }

    float cgpa; 
    printf("ENTER CGPA OF STUDENT : ");
    scanf("%f", &cgpa);
    p[count].cg = cgpa;

    count++;
}

int LS(data *p, int r)
{
    if (count == 0)
    {
        printf("Nothing to Sort, it is Empty!\n");
        return -1;
    }
    for (int i = 0; i < count; i++)
    {
        if (p[i].roll == r)
        {
            return i;
            break;
        }
    }
    return -1;
}

void display(data *p, int i)
{
    if (count == 0)
    {
        printf("The Database is empty!\n");
        return;
    }
    else if (i == -1)
    {
        printf("Invalid Index");
        return;
    }
    else
    {
        printf("NAME OF STUDENT %s\n", p[i].name);
        printf("ROLL NUMBER OF STUDENT %d\n", p[i].roll);
        printf("BRANCH OF STUDENT %s\n", p[i].branch);
        printf("CGPA OF STUDENT %f\n", p[i].cg); 
    }
}

void SortRoll(data *p)
{
    if (count == 0)
    {
        printf("Nothing to Sort, it is Empty!\n");
        return;
    }
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++) 
        {
            if (p[j].roll > p[j + 1].roll)
            {
                data temp = p[j]; 
                p[j] = p[j + 1];   
                p[j + 1] = temp;   
            }
        }
    }
    printf("SUCCESSFULLY SORTED!\n");
}

int BS(data *p, int r)
{
    if (count <= 0)
        return -1;
    else
    {
        int l = 0;
        int h = count - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (p[mid].roll == r)
                return mid;
            else if (p[mid].roll < r)
                l = mid + 1;
            else
                h = mid - 1;
        }
        return -1;
    }
}

void InsertionSort(data *p)
{
    for (int i = 1; i < count; i++)
    {
        int j = i - 1;
        float x = p[i].cg; 
        while (j >= 0 && p[j].cg < x) 
        {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1].cg = x; 
    }
}

int main()
{
    data *p = (data *)malloc(50 * sizeof(data));
    for (int i = 0; i < 50; i++)
    {
        p[i].roll = -1; 
    }

    int choice;
    do
    {
        printf("\n");
        printf("0.Exit the program\n");
        printf("1.Add Student Details\n");
        printf("2.Display by Roll Number (LS)\n");
        printf("3.Bubble Sort the data based on Roll Number\n");
        printf("4.Display by Roll Number (BS)\n");
        printf("5.Insertion Sort Based on CG\n");
        printf("\nEnter Choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            addStudent(p);
            printf("Details Recorded Successfully!\n");
            break;
        case 2:
            printf("\nEnter Roll Number : ");
            int r;
            scanf("%d", &r);
            int x = LS(p, r);
            display(p, x);
            break;
        case 3:
            SortRoll(p);
            break;
        case 4:
            printf("\nEnter Roll Number : ");
            scanf("%d", &r);
            x = BS(p, r);
            display(p, x);
            break;
        case 5: 
            InsertionSort(p);
            break;
        default:
            printf("Wrong Input, Try Again!");
            break;
        }
    } while (choice != 0);
}
