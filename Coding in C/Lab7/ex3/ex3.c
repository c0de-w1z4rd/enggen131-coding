#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int total, winners;
    double split;
    printf("Total:\n");
    scanf("%d", &total);
    printf("Winners:\n");
    scanf("%d", &winners);
    split = (double)total / winners;
    printf("Shared: $%.2f", split);
    return 0;
}

