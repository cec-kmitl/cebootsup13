#include <stdio.h>

int main()
{
    char c;
    scanf("%c", &c);
    if (c >= 48 && c <= 57) printf("This is digit character");
    else if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) printf("This is an alphabet");
    else printf("This is special character");
    return 0;
}