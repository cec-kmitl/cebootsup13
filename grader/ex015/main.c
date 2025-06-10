#include <stdio.h>

int main()
{
    int ms;
    scanf("%d", &ms);

    if (ms < 3 * 60 * 1000)
    {
        printf("Raw");
    }
    else if (ms <= 5 * 60 * 1000)
    {
        printf("Soft Boiled Egg");
    }
    else if (ms <= 8 * 60 * 1000)
    {
        printf("Medium Boiled Egg");
    }
    else
    {
        printf("Hard Boiled Egg");
    }

    return 0;
}