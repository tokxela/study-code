#include <stdio.h>

int main() {
    int myNumbers[5] = {10, 20, 30, 40, 50};

    int *pFirst, *pSecond;
    pFirst = &myNumbers[0];
    pSecond = &myNumbers[4];

    printf("%p\n", pFirst);
    printf("%p\n", pSecond);
    // Differenz zwischen Adressen in Bytes
    printf("%ld\n", pSecond - pFirst);

    return 0;
}