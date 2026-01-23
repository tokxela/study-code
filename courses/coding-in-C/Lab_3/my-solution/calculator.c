#include <stdio.h>
#include <stdbool.h>

float ask_for_number(unsigned short n) {
    float number;
    if (n == 1) {
        printf("Please enter 1st number: ");
    } else if (n == 2) {
        printf("Please enter 2nd number: ");
    }
    if (scanf("%f", &number) != 1) {
        printf("Something went wrong. Please try again.\n");
        number = ask_for_number(n);
    }
    return number;
}

int main () {
    while (true) {
        printf("%f", ask_for_number(1));
    }
    return 1;
}