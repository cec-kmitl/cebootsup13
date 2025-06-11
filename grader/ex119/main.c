#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf((a + b) % 2 ? "Odd" : "Even");
    return 0;
}