#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) printf("%c", c < 97 ? c + 32 : c - 32);
}