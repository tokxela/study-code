#include <stdio.h>
#include <stdbool.h>

typedef enum {
    ADD = 0,
    MIN,
    MULT,
    DIV
} Operation;

float ask_for_number(unsigned short n) {
    float number;
    char c;
    if (n == 1) {
        printf("Please enter 1st number: ");
    } else if (n == 2) {
        printf("Please enter 2nd number: ");
    }
    if (scanf("%f", &number) != 1) {
        printf("Something went wrong. Please try again.\n");
        while ((c = getchar()) != '\n' && c != EOF); // reading and cleaning the wrong input line
        number = ask_for_number(n);
    }
    return number;
}

short ask_for_operation() {
    char c;
    printf("Please enter operation (+, -, * or /): ");
    c = getchar();
    switch (c) {
    case '+':
        return ADD;
    case '-':
        return MIN;
    case '*':
        return MULT;
    case '/':
        return DIV;
    default:
        printf("Something went wrong. Please try again.\n");
        return ask_for_operation();
        break;
    }
    while ((c = getchar()) != '\n' && c != EOF); // reading and cleaning the wrong input line    
}

int main () {
    printf("%i",ask_for_operation());
    return 1;
}