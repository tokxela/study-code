#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int A_INDEX = 65;


void print_file_labels () {
    printf("    ");
    for (int i = 0; i < 8; i++) {
        printf("%-4c", A_INDEX + i);
    }
}

void print_blank_horizontal_line() {
    printf("  ");
    for (int i = 0; i < 8; i++) {
        printf("+---");
    }
    printf("+");
}

void print_horizontal_line(int row) {
    row = abs(9 - row / 2);
    bool is_white = row % 2;
    printf("%i |", row);
    for (int i = 0; i < 8; i++) {
        if (is_white) {
            printf("   ");
        } else {
            printf("###");
        }
        printf("|");
        is_white = !is_white;
    }
    printf(" %i", row);
}

int main() {
    for (int i = 0; i < 19; i++) {
        if (i == 0 || i == 18) {
            print_file_labels();
        } else if (i % 2 != 0) {
            print_blank_horizontal_line();
        } else {
            print_horizontal_line(i);
        }
    printf("\n");
    }
    return 0;
}
