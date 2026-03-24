#include <iostream>
#include <iomanip>

int main(){
	
	std::cout << std::setfill('0')	//Ustawiamy aby program dopelnial puste miejsca liczba 0
		<< std::setw(10)	//Ustawiamy szerokosc pola do danej wartości (w tym przypadku 10)
		<< std::hex		//Przekazujemy dla programu aby wyswietlil zadana liczbe
		<< std::setiosflags (std::ios::showbase);	//Ustawiamy flagi dotyczące naszego programu, a w tym przypadku ustawiamy aby program
													//wyswietlal baze systemu szesnastkowego
	
	std::cout << 10000 << std::endl;	//Wyswietlenie danej liczby
	
	double pi=3.14159;	//Dodajemy zmienna i przypisujemy jej wartosc
	std::cout << std::setprecision(3)	//Ustawiamy dokladnosc z jaka ma byc wyswietlana dana liczba
		<< pi;
	
	return 0;
}