#include <stdio.h>

int main()
{
    int year;
    scanf("%d", &year);
    if (year < 1)
    {
        printf("Error");
        return 0;
    }
    printf((!(year % 4) && year % 100) || !(year % 400) ? "Leap Year" : "Not a Leap Year");
    return 0;
}