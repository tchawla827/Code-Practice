
#include<stdio.h>
#include <stdlib.h>
#include <limits.h> 

#define MAX_DATES 10
int count=0;

typedef struct date {
    int day;
    int month;
    int year;
} Date;


void add_date(Date *p) {
        if (count >= 10) {
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

void merge(Date *p, int l, int mid, int h) {
    int i, j, k;
    Date *C = (Date *)malloc((h - l + 1) * sizeof(Date));

    i = l;
    j = mid + 1;
    k = l;

    while (i <= mid && j <= h) {
        
        if (p[i].year < p[j].year ||
            (p[i].year == p[j].year && p[i].month < p[j].month) ||
            (p[i].year == p[j].year && p[i].month == p[j].month && p[i].day < p[j].day)) {
            C[k++] = p[i++];
        } else {
            C[k++] = p[j++];
        }
    }

    while (i <= mid) {
        C[k++] = p[i++];
    }
    while (j <= h) {
        C[k++] = p[j++];
    }

    for (int m = l; m <= h; m++) {
        p[m] = C[m - l];
    }

    free(C);
}

void merge_sort(Date *p, int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        merge_sort(p, l, mid);
        merge_sort(p, mid + 1, h);
        merge(p, l, mid, h);
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

    do {
        printf("\n");
        printf("0. Exit the program\n");
        printf("1. Add Date\n");
        printf("2. Display all dates\n");
        printf("3. MergeSort the dates\n");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("ThankYou!\n");
                free(p);
                exit(1);
            case 1:
                add_date(p);
                break;
            case 2:
                display(p);
                break;
            case 3:
                merge_sort(p, 0, count - 1);
                break;
        }

    } while (choice != 0);

    free(p);
    return 0;
}