#include<stdio.h>
#define OK 0
#define ROOMS_ALL 36
#define ROOMS_ON_ONE_LEVEL 4

int main()
{
    int n, entry, level;

    printf("Input number of a flat: ");
    scanf("%d", &n);

    entry = (n - 1) / ROOMS_ALL;
    n = n - entry * ROOMS_ALL;
    level = (n - 1) / ROOMS_ON_ONE_LEVEL;

    printf("Entry is %d and level is %d ", entry + 1, level + 1);
    return 0;
}