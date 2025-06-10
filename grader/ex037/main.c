#include <stdio.h>

int main()
{
    int hp, lvl, dmg;
    scanf("%d %d", &hp, &lvl);
    dmg = 180 + (lvl * 20);
    if (dmg >= hp)
    {
        printf("hehehehaw %d", hp - dmg);
    }
    else if (dmg < hp)
    {
        printf("rawr %d", hp - dmg);
    }
    return 0;
}