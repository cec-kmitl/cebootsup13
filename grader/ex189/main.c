#include <stdio.h>
#include <math.h>

int main()
{
    // Xn = a × rⁿ, โดยที่ n เริ่มจาก 0 ถึง 9
    int a, r;
    int xn;

    scanf("%d , %d", &a, &r);
    xn = a;
    for (int i = 0; i < 10; i++)
    {
        printf("%d", xn);
        if (i < 9) printf(", ");
        xn *= r;
    }
}