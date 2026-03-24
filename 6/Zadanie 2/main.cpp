#include <iostream>
#include <fstream>

int main() {
    char plik[41];
    char litera;
	
    std::cout << "Podaj nazwe lub sciezke pliku do maksymalnie 40 znakow:" << std::endl;
    std::cin.getline(plik, 41);		//Pobieramy z klawiatury nazwe lub sciezke pliku
	
    std::cout << "Podaj jedna litere:" << std::endl;
    std::cin.get(litera);		//Pobieramy litere ktora bedziemy liczyc
	
    std::ifstream file;		//Obsluga wejsciowego strumienia plikowego
	file.open(plik);
    if (!file.is_open()) {		//Sprawdzenie czy plik poprawnie otwarto
        std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
        exit(EXIT_FAILURE);
    }
	
	int licznik = 0;
    char x;		//Zliczanie podanej litery
    while (file.get(x)) {
        if (x == litera) {
            licznik++;
        }
    }
	
	if (!file.eof() && file.fail()) {		//Sprawdzanie czy poprawnie odczytano
		std::cout << "Blad podczas odczytu pliku." << std::endl;
	}

    std::cout << "Litera " << litera << " wystepuje w pliku " << licznik << " razy." << std::endl;
	file.close();		//Zamkniecie pliku
	
    return EXIT_SUCCESS;
}
