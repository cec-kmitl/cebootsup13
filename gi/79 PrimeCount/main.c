#include <stdio.h>
#include <stdbool.h> // For using boolean type
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);

    if (num <= 1) {
        printf("0\n");
        return 0;
    }

    bool *isPrime = (bool *)malloc((num + 1) * sizeof(bool));
    if (isPrime == NULL) {
        return 1;
    }

    for (int i = 0; i <= num; i++) {
        isPrime[i] = true;
    }

    isPrime[0] = false;
    isPrime[1] = false;

    for (int p = 2; p * p <= num; p++) {
        if (isPrime[p] == true) {
            for (int i = p * p; i <= num; i += p)
                isPrime[i] = false;
        }
    }

    int count = 0;
    for (int p = 2; p <= num; p++) {
        if (isPrime[p]) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}