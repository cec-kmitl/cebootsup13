#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if (a <= 0)
    {
        printf("cannot built cube");
    }
    else
    {
        printf("%d", (a * a * a));
    }
    return 0;
}