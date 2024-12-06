//IIT2023150
//Ques3

#include <stdio.h>
#define MAX 100

int main()
{
    int i, j, n, p[MAX], bt[MAX], wt[MAX], tat[MAX], ct[MAX];
    float awt = 0, atat = 0;

    printf("Enter the number of process :- ");
    scanf("%d", &n);

    printf("Enter the process number :-");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("Enter the burst time of the process :-");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {

                int temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    ct[0] = p[0] + bt[0];

    printf("Process  burst time  completion time   waiting time  turn around time \n");
    for (int i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;

        ct[i + 1] = ct[i] + bt[i + 1];
        tat[i] = ct[i] - p[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];
        printf("   %d\t   %d\t\t  %d\t\t %d\t\t%d\n", p[i], bt[i], ct[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;

    printf("Average waiting time = %f\n", awt);
    printf("Average turn around time = %f\n", atat);
    printf("GANTT CHART:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d ", p[i]);
        if (i < n - 1)
        {
            printf("|");
        }
    };
    return 0;
}