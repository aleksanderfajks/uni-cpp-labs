#include <stdio.h>

void echo(char character) {
    printf("Echo: %c\n", character);
    fflush(stdout);
}

void write(char character) {
    FILE *fPtr = fopen("plik.txt", "a");    
    if (fPtr != NULL) {
        fputc(character, fPtr);
        fclose(fPtr);
    } else {
        printf("Blad otwarcia pliku \n");
    }
}