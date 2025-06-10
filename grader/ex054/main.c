#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char vol[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    scanf("%s", str);
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (str[i] == vol[j])
            {
                count++;
                break;
            }
        }
    }
    printf("Number of vowels : %d", count);
    return 0;
}