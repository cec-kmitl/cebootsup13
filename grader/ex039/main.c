#include <stdio.h>

int main()
{
    int temp;
    scanf("%d", &temp);
    if (temp > 25)
    {
        printf("The temperature is too high.");
    }
    else if (temp >= 17)
    {
        printf("The temperature is perfect.");
    }
    else
    {
        printf("The temperature is too low.");
    }
    return 0;
}