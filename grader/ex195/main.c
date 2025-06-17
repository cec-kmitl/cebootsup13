#include <stdio.h>

int main()
{
    char arr[100];
    scanf("%s", arr);

    for (int i = 0; arr[i] != '\0'; i++)
    {
        printf("%c", arr[i] ^ 127);
    }

    return 0;
}
