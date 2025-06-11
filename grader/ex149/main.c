#include <stdio.h>

int main()
{
    int x, sum = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &x);
        if (!(x % 2))
        {
            sum += x;
        }
    }
    printf("%d\n", sum);

    return 0;
}
