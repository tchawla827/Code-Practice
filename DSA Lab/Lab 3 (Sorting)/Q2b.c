
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATES 10

int count = 0;

typedef struct date {
    int day;
    int month;
    int year;
} Date;

void add_date(Date *p) {
    if (count >= MAX_DATES) {
        printf("Structure full, can't add more dates!\n");
    } else {
        printf("ENTER DATE : ");
        scanf("%d", &(p[count].day));
        printf("ENTER MONTH : ");
        scanf("%d", &(p[count].month));
        printf("ENTER YEAR : ");
        scanf("%d", &(p[count].year));
        count++;
        printf("Date Added Successfully!\n");
    }
}

int partition(Date *p, int l, int h) {
    int pivot = p[l].year;
    int i = l - 1;
    int j = h + 1;

    while (1) {
        do {
            i++;
        } while (p[i].year < pivot);
        
        do {
            j--;
        } while (p[j].year > pivot);

        if (i >= j)
            return j;

        // Swap dates
        Date temp = p[i];
        p[i] = p[j];
        p[j] = temp;
    }
}

void QuickSort(Date *p, int l, int h) {
    if (l < h) {
        int j = partition(p, l, h);
        QuickSort(p, l, j);
        QuickSort(p, j + 1, h);
    }
}

void display(Date *p) {
    for (int i = 0; i < count; i++) {
        printf("%d. %02d-%02d-%04d\n", i + 1, p[i].day, p[i].month, p[i].year);
    }
}

int main() {
    int choice;
    Date *p = (Date *)malloc(MAX_DATES * sizeof(Date));

    if (p == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    do {
        printf("\n");
        printf("0. Exit the program\n");
        printf("1. Add Date\n");
        printf("2. Display all dates\n");
        printf("3. Quicksort the dates\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("ThankYou!\n");
                free(p);
                return 0;
            case 1:
                add_date(p);
                break;
            case 2:
                display(p);
                break;
            case 3:
                QuickSort(p, 0, count - 1);
                printf("Dates sorted successfully!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (choice != 0);

    free(p);
    return 0;
}
