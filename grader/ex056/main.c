#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    if (x > 0)
    {
        printf("It is a positive number");
    }
    else if (x < 0)
    {
        printf("It is a negative number");
    }
    else
    {
        printf("It is zero");
    }
    return 0;
}