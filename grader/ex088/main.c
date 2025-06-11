#include <stdio.h>

int main()
{
    float a, wa, b, wb, c, wc;
    scanf("%f %f\n%f %f\n%f %f", &a, &wa, &b, &wb, &c, &wc);
    printf("%.2f", ((a * wa) + (b * wb) + (c * wc)) / (wa + wb + wc));
    return 0;
}