#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// You can assume the converted number will have fewer digits than MAX_SIZE
#define MAX_SIZE 100

int main(void)
{
    int bits[MAX_SIZE];
    int numBits = 0;
    int number;
    printf("Enter a number:\n");
    scanf("%d", &number);
    while (number > 0) {
        if (number % 2 == 0) {
            bits[numBits] = 0;
        }
        else {
            bits[numBits] = 1;
        }
        number = number / 2;
        numBits++;
    }
    int i;
    for (i = (numBits - 1); i >= 0; i--) {
        printf("%d", bits[i]);
    }

    return 0;
}
