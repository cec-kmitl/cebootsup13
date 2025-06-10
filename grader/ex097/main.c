#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", n * ((n > 0) - (n < 0)));
    return 0;
}