#include <stdio.h>

int main()
{
    float x, y;
    char o;

    scanf("%f\n%c\n%f", &x, &o, &y);

    if (o == '+')
    {
        int z = x + y;
        printf("%d", z);
    }
    else if (o == '-')
    {
        int z = x - y;
        printf("%d", z);
    }
    else if (o == '*')
    {
        int z = x * y;
        printf("%d", z);
    }
    else if (o == '/')
    {
        printf("%.2f", x / y);
    }
    return 0;
}