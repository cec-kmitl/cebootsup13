#include <stdio.h>
#include <string.h>

void Decode(char text[100],int size)
{

    //output "The_book_is_the_key!"
    // printf("%lu\n", strlen(text));
    char after[100] = {};
    for (int i = 0; i < strlen(text); i++) {
        // if (text[i] == '_' || text[i] == '!' || text[i] == ' ') {
        //     after[i] = text[i];
        // } else {
            if (text[i] >= 'a' && text[i] <= 'z') {
                after[i] = (text[i] - 'a' + size) % 26 + 'a';
            } else if (text[i] >= 'A' && text[i] <= 'Z') {
                after[i] = (text[i] - 'A' + size) % 26 + 'A';
            } else {
                after[i] = text[i];
            }
            printf("%c", after[i]);
        // }
    }
    // after[size+1] = '\0';
    // printf("%s\n",after);
}

int main()
{
    char str[100] = {};
    int num;
    //input "Lzw_tggc_ak_lzw_cwq!|8"
    scanf("%[^|]|%d", str, &num);
;
    Decode(str, num);
    return 0;
}