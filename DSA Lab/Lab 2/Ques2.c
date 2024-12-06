//IIT2023150 Tavish Chawla
#include <stdio.h>

void print(int stamps[], int count) {
    printf("{ ");
    for (int i = 0; i < count; i++) {
        printf("%d ", stamps[i]);
    }
    printf("}\n");
}

void find(int L[], int n, int V, int stamps[], int c, int index) {
    if (V == 0) {
        
        print(stamps, c);
        return;
    }

    for (int i = index; i < n; i++) {
        if (V >= L[i]) {
            stamps[c] = L[i];
            find(L, n, V - L[i], stamps, c + 1, i);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of stamp denominations: ");
    scanf("%d", &n);

    int L[100];
    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &L[i]);
    }

    int V;
    printf("Enter V: ");
    scanf("%d", &V);

    int stamps[100];
    printf("Combinations %d:\n", V);
    find(L, n, V, stamps, 0, 0);

    return 0;
}
