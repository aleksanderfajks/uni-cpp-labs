#include <stdio.h>

void add(int *result, int number) {
    *result += number;  //Dodawanie liczby do wyniku
    printf("Wynik: %d\n", *result);
}

void multiply(int *result, int number) {
    *result *= number;  //Mnożenie liczby do wyniku
    printf("Wynik: %d\n", *result);
}

typedef enum EventDescriptor {  //Możliwe zdarzenia
    positive,
    negative
} EventDescriptor_t;

//Deklaracje zapowiadające
typedef struct State State_t;
const State_t * addition(EventDescriptor_t event);
const State_t * multiplication(EventDescriptor_t event);

typedef const State_t * (*EventHandler)(EventDescriptor_t);
typedef void (*StateExecutor)(int *result, int number);

struct State {  //Struktura stanu maszyny
    EventHandler handler;
    StateExecutor executor;
};

//Predefiniowane stany
static const State_t ADDITION = {addition, add};  //Stan sumowania
static const State_t MULTIPLICATION = {multiplication, multiply};  //Stan mnożenia

//Obsługa zdarzenia w stanie sumowania
const State_t * addition(EventDescriptor_t event){
    if (event == positive) {
        return &ADDITION;
    } else {
        return &MULTIPLICATION;
    }
}

//Obsługa zdarzenia w stanie mnożenia
const State_t * multiplication(EventDescriptor_t event){
    if (event == positive) {
        return &ADDITION;
    } else {
        return &MULTIPLICATION;
    }
}

void handleEvent(EventDescriptor_t event, int *result, int number) {
    static const State_t *state = &ADDITION;
    state->executor(result, number);
    state = state->handler(event);
}

void exec(){
	int wynik = 1;
    int liczba;
	
	while (1) {
        scanf("%d", &liczba);
        if (liczba == 0) {
            printf("Wynik koncowy: %d\n", wynik);
            break;
        } else if (liczba > 0) {
            handleEvent(positive, &wynik, liczba);
        } else {
            handleEvent(negative, &wynik, liczba);
        }
    }
}

int main() {
	exec();
    return 0;
}