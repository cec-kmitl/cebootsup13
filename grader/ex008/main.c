#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);

    if ((x < 3) && (x > 0))
    {
        printf("%d", 0);
    }
    else if (x >= 3)
    {
        printf("%d", (x - 2) * 180);
    }
    else
    {
        printf("error\n");
    }
    return 0;
}