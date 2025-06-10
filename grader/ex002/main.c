#include <stdio.h>

int main()
{
    int h, m, s;
    scanf("%d/%d/%d", &h, &m, &s);
    if (m >= 12 || s >= 12)
    {
        printf("Error");
    }
    else
    {
        printf("Light Realm\n%d:%d:%d\nShadow Realm\n%d:%d:%d\n", h, m * 5, s * 5, h + 12, m * 5, s * 5);
    }
    return 0;
}