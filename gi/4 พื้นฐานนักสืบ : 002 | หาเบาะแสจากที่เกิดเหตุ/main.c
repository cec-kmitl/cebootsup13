#include <stdio.h>

char toUpper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int letterToDigit(char letter) {
    switch (letter) {
        case 'A': return 4;
        case 'B': return 8;
        case 'E': return 3;
        case 'G': return 6;
        case 'I': return 1;
        case 'O': return 0;
        case 'S': return 5;
        case 'T': return 7;
        default: return 1; // อื่นๆ
    }
}

int main() {
    // input
    char og[100];
    scanf("%s", og);
    char itemName[100];
    // convert to uppercase
    for (int i = 0; og[i] != '\0'; i++) {
        itemName[i] = toUpper(og[i]);
    }
    // convert letters to digits
    int result = 0;
    for (int i = 0; itemName[i] != '\0'; i++) {
        result += letterToDigit(itemName[i]);
    }
    
    char output = result + 64;
    printf("Item '%s' code: %1c\n", og, output);
    return 0;
}