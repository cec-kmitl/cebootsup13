#include <stdio.h>

int main()
{
    int a, b, x;
    scanf("%d %d", &a, &b);

    if (!a && !b) x = 0;
    else if (a == b) x = a * b + 42;
    else if (a > b) x = a - b + 99;
    else x = a + b * 2 - 7;
    printf("พลังรวมของคุณคือ: %d", x);
    return 0;
}