#include <stdio.h>

int main()
{
    int h, m;
    scanf("%d/%d", &h, &m);
    printf("%d m", h * 60 + m);
    return 0;
}