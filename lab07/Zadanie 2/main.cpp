#include <iostream>

int main(){
	
	unsigned int n;
	unsigned int m;
	std::cout << "Podaj rozmiar macierzy n: ";
	std::cin >> n;
	std::cout << "Podaj rozmiar macierzy m: ";
	std::cin >> m;
	
	int **tab = new int*[n];
	for (unsigned int i=0; i<n; i++) {
		tab[i]=new int[m];
	}
	
	int x;
	std::cout << "Podaj " << n*m << " liczb calkowitych:" << std::endl;
	for(unsigned int i=0; i<n; i++) {
		for(unsigned int j=0; j<m; j++) {
			std::cin >> tab[i][j];
		}
	}
	
	std::cout << "Zawartosc tablicy:" << std::endl;
	for(unsigned int i=0; i<n; i++) {
		for(unsigned int j=0; j<m; j++) {
			std::cout << tab[i][j] << " ";
		}
		std::cout << std::endl;
	}
	
	for(unsigned int i=0; i<n; i++) {
		delete[] tab[i];
	}
	delete[] tab;
	
	return 0;
	
}