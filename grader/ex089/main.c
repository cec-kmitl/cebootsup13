#include <stdio.h>

int main()
{
    int x, y, s = 0;
    scanf("%d %d", &x, &y);
    if (x % 2 == y % 2) s++;
    if (x / 10 == y / 10) s++;
    if (!((x + y) % 10)) s++;
    if (!(x > y ? x % y : y % x)) s++;
    if ((x > y ? x - y : y - x) <= 20) s++;
    printf(s >= 3 ? "Likely" : "Unlikely");
    return 0;
}