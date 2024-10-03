#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int value;
    printf("Enter value:\n");
    scanf("%d", &value);
    printf("One more: %d\n", value + 1);
    return 0;
}
