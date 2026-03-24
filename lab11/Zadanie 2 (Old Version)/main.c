#include <stdio.h>

typedef enum StateDescriptor {  //Możliwe stany
    sumowanie,
    mnozenie,
    stop
} StateDescriptor_t;

typedef enum EventDescriptor {  //Możliwe zdarzenia
    dodatnia,
    ujmena,
    zero
} EventDescriptor_t;

typedef StateDescriptor_t (*EventHandler)();    //Wskaźnik funkcji do obsługi zdarzeń

typedef struct State {  //Struktura stanu maszyny
    StateDescriptor_t stateDescriptor;
    EventDescriptor_t EventDescriptor;
    EventHandler handler;
} State_t;

//Funkcje obsługi zdarzeń
StateDescriptor_t dodatniaSuma(int *wynik, int liczba) {   //Obsługa zdarzenia liczby dodatniej w stanie sumowania
    *wynik += liczba;
    printf("Wynik: %d\n", *wynik);
    return sumowanie;
}
StateDescriptor_t ujmenaSuma(int *wynik, int liczba) {    //Obsługa zdarzenia liczby ujemnej w stanie sumowania
    *wynik *= liczba;
    printf("Wynik: %d\n", *wynik);
    return mnozenie;
}
StateDescriptor_t zeroSuma(int *wynik, int liczba) {    //Obsługa zdarzenia zera w stanie sumowania
    printf("Koniec działania. Wynik końcowy: %d\n", *wynik);
    return stop;
}
StateDescriptor_t dodatniaMnozenie(int *wynik, int liczba) {   //Obsługa zdarzenia liczby dodatniej w stanie mnożenia
    *wynik += liczba;
    printf("Wynik: %d\n", *wynik);
    return sumowanie;
}
StateDescriptor_t ujmenaMnozenie(int *wynik, int liczba) {    //Obsługa zdarzenia liczby ujemnej w stanie mnożenia
    *wynik *= liczba;
    printf("Wynik: %d\n", *wynik);
    return mnozenie;
}
StateDescriptor_t zeroMnozenie(int *wynik, int liczba) {    //Obsługa zdarzenia zera w stanie mnożenia
    printf("Koniec działania. Wynik końcowy: %d\n", *wynik);
    return stop;
}

void handleEvent (EventDescriptor_t event, int *wynik, int liczba) {
    static const State_t stateMachine[] = {  //Tabela stanów
        {sumowanie, dodatnia, dodatniaSuma},
        {sumowanie, ujmena, ujmenaSuma},
        {sumowanie, zero, zeroSuma},
        {mnozenie, dodatnia, dodatniaMnozenie},
        {mnozenie, ujmena, ujmenaMnozenie},
        {mnozenie, zero, zeroMnozenie}
    };

    StateDescriptor_t currentState = sumowanie;
    for (unsigned int i = 0; i < sizeof(stateMachine)/sizeof(State_t); i++) {
        if (stateMachine[i].stateDescriptor == currentState && stateMachine[i].EventDescriptor == event) {
            currentState = stateMachine[i].handler(wynik, liczba);
            break;
        }
    }
}

int main() {
    int wynik = 1;
    int liczba;

    while (1) {
        scanf("%d", &liczba);
        if (liczba == 0) {
            handleEvent(zero, &wynik, liczba);
            break;
        } else if (liczba > 0) {
            handleEvent(dodatnia, &wynik, liczba);
        } else {
            handleEvent(ujmena, &wynik, liczba);
        }
    }

    return 0;
}

// Do poprawy jest to aby program kolejne liczby dodawał lub mnozył a nie te odrazu podane
// +sprawdzić ogólnie czy się zgadza
// +poprawić schemat na tablecie