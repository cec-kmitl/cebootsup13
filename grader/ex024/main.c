#include <stdio.h>

int main()
{
    int late, fee;
    scanf("%d %d", &late, &fee);

    if (fee <= 7)
    {
        printf("Late fee: 0");
        return 0;
    }

    if (fee <= 14)
    {
        printf("Late fee: %d", late * 10 * (fee - 7));
    }
    else
    {
        printf("Late fee: %d", (late * 70) + (late * 20 * (fee - 14)));
    }
    return 0;
}