#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[1024];
    scanf("%s", str);
    if (str[0] == '0') { printf("true\n"); return 0;}
    else {}
    int len = strlen(str);
    int i = 0;
    bool hasDigit = false;
    bool hasE = false;
    bool hasDot = false;
    bool afterE = false;
    bool valid = true;

    if (str[i] == '+' || str[i] == '-') {
        i++;
    }

    for (; i < len; i++) {
        char c = str[i];

        if (isdigit(c)) {
            hasDigit = true;
        }
        else if (c == '.') {
            if (hasDot || hasE) {
                valid = false;
                break;
            }
            hasDot = true;
        }
        else if (c == 'e' || c == 'E') {
            if (hasE || !hasDigit || i == len - 1) {
                valid = false;
                break;
            }
            hasE = true;
            afterE = true;
            i++;
            if (str[i] == '+' || str[i] == '-') {
                i++;
            }
            if (i >= len || !isdigit(str[i])) {
                valid = false;
                break;
            }
            while (i < len && isdigit(str[i])) {
                i++;
            }
            if (i != len) {
                valid = false;
            }
            break;
        }
        else if (c == '+' || c == '-') {
            valid = false;
            break;
        }
        else {
            valid = false;
            break;
        }

    }

    if (!hasDigit) valid = false;

    if (!valid) {
        printf("false\n");
    } else { printf("true\n");}

    return afterE;
}
