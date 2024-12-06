#include <stdio.h>

// Function to convert decimal to binary
void dectobin(int decimal) {
    if (decimal == 0) {
        printf("Binary: 0\n");
        return;
    }

    int binary[32];  // Assuming 32-bit binary representation
    int index = 0;

    while (decimal > 0) {
        binary[index++] = decimal % 2;
        decimal /= 2;
    }

    printf("Binary: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

int main() {
    int decimal;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    dectobin(decimal);

    return 0;
}
