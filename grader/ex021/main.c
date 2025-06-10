#include <stdio.h>
#include <math.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%.0lf", sqrt((a * a) + (b * b)));
    return 0;
}