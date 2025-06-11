#include <stdio.h>

int main()
{
    int h1, m1, s1, h2, m2, s2,calculated;
    char t;

    scanf("%d/%d/%d-%d/%d/%d-%c", &h1, &m1, &s1, &h2, &m2, &s2, &t);
    calculated = ((h1 * 3600) + (m1 * 60) + s1) - ((h2 * 3600) + (m2 * 60) + s2);
    if (h1 > h2) calculated -= 86400;
    calculated *= -1;

    if (t == 's') printf("%d %c", calculated, t);
    else if (t == 'm') printf("%d %c", calculated / 60, t);
    else if (t == 'h') printf("%d %c", calculated / 3600, t);
    else printf("Error");
    return 0;
}