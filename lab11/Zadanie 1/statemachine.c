#include <stdio.h>
#include <stdbool.h>
#include "statemachine.h"
#include "reader.h"

extern void echo(char character);
extern void write(char character);

typedef enum State{
    ECHO,
    WRITE
} State_t;

void exec(){
    State_t state = ECHO;
    bool isRunning = true;

    while(isRunning){
        char character = readChar();
        switch (state){
            case ECHO:
                if (character == 'w') {
                    state = WRITE;
                } else if (character == 'q') {
                    isRunning = false;
                } else {
                    echo(character);
                }
                break;
            case WRITE:
                if (character == 'e') {
                    state = ECHO;
                } else if (character == 'q') {
                    isRunning = false;
                } else {
                    write(character);
                }
                break;
        }
    }
}