#include <stdio.h>

int main() {

    char word[] = "Curly bird catches the worm";
    char* pWord = word;

    printf("%s\n", pWord);
    printf("%s\n", word);

    pWord = 'E';


    return 0;
}