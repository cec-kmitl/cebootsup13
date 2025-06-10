#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    if (((a + b + c) != 180) || a <= 0 || b <= 0 || c <= 0)
    {
        printf("Invalid triangle");
        return 0;
    }
    if ((a == b) && (b == c))
    {
        printf("Equilateral triangle");
    }
    else if ((a == b) || (a == c) || (b == c))
    {
        printf("Isosceles triangle");
    }
    else
    {
        printf("Scalene triangle");
    }

    return 0;
}