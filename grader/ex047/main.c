#include <stdio.h>

int main()
{
    int gpa;

    scanf("%d", &gpa);
    if (gpa > 100 || gpa < 0)
    {
        printf("GPA = out of range");
    }
    else if (gpa >= 80)
    {
        printf("GPA = A");
    }
    else if (gpa >= 60)
    {
        printf("GPA = B");
    }
    else if (gpa >= 40)
    {
        printf("GPA = C");
    }
    else if (gpa >= 0)
    {
        printf("GPA = D");
    }
    return 0;
}