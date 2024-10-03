#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int lCap, sCap, contain, large, small;
    printf("Large capacity:\n");
    scanf("%d", &lCap);
    printf("Small capacity:\n");
    scanf("%d", &sCap);
    printf("Number of items:\n");
    scanf("%d", &contain);
    large = contain / lCap;
    contain = contain - (lCap * large);
    small = contain / sCap;
    contain = contain - (sCap * small);
    printf("Allocated:\n - Large: %d\n - Small: %d\n - Scrap: %d\n", large, small, contain);
    return 0;
}

