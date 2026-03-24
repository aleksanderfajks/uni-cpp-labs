#include <iostream>
#include <fstream>

int main(int argc, char ** argv) {
	
	std::ofstream plik;
	plik.open("compilation.txt");
	if (!plik.is_open()) {		//Sprawdzenie czy plik poprawnie otwarto
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
		exit(EXIT_FAILURE);
	}
	
	for (int i=1; i<argc; i++){
		
		std::ifstream files;		//Obsluga wejsciowego strumienia plikowego
		files.open(argv[i]);
		if (!files.is_open()) {		//Sprawdzenie czy plik poprawnie otwarto
			std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
			exit(EXIT_FAILURE);
		}
		
		char bufor[21];
		files.getline(bufor, 21);
		plik << bufor;
		
		files.close();		//Zamkniecie pliku
		
	}
	
	plik.close();		//Zamkniecie pliku
	
	return EXIT_SUCCESS;
}

//Komenda uruchamiająca - a.exe "One.txt" "Two.txt" "Three.txt" "Four.txt" "Five.txt"