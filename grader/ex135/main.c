#include <stdio.h>
#include <time.h>

int main()
{
    time_t t;
    struct tm tm = {0};
    char buffer[50];

    tm.tm_year = 2025 - 1900;
    tm.tm_mon = 5;
    tm.tm_mday = 10;

    t = mktime(&tm);

    strftime(buffer, sizeof(buffer), "%A @ %-d|%b|%Y", localtime(&t));

    printf("%s\n", buffer);

    return 0;
}