#include <stdio.h>

int main()
{
    int r, h;
    scanf("%d %d", &r, &h);
    if (r < 0 || h < 0)
    {
        printf("Invalid");
        return 0;
    }
    printf("%.2f", 3.14 * r * r * h / 3);
    return 0;
}