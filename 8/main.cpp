#include <iostream>

typedef struct Student{
	char name[10];
	unsigned short age;
	unsigned long index;
	
	struct{
		float physics;
		float chemistry;
	}course;
	
}StudentPwr;

void showBase(StudentPwr *stru, unsigned int size);

int main(){
	unsigned int numberStu;
	std::cout << "Podaj liczbe studentow: ";
	std::cin >> numberStu;
	StudentPwr* ieaW12N = new StudentPwr[numberStu];
	
	for(int i=0; i<numberStu; i++){
		std::cout << "Podaj imie" << i+1 << "-ego studenta: ";
		std::cin >> ieaW12N[i].name;
		std::cout << "Podaj wiek tego studenta: ";
		std::cin >> ieaW12N[i].age;
		std::cout << "Podaj numer indeksu tego studenta: ";
		std::cin >> ieaW12N[i].index;
		std::cout << "Podaj ocene tego studenta z fizykii: ";
		std::cin >> ieaW12N[i].course.physics;
		std::cout << "Podaj ocene tego studenta z chemii: ";
		std::cin >> ieaW12N[i].course.chemistry;
		
	}
	
	showBase(ieaW12N, numberStu);
	
	std::cout << "Rozmiar paddingu to: " << sizeof(Student)-sizeof(char)-sizeof(unsigned short)-sizeof(unsigned long)-sizeof(float);
	
	delete [] ieaW12N;
	return 0;
}

void showBase(StudentPwr *stru, unsigned int size){
	for(int j=0; j<size; j++){
		std::cout << "Student nr. " << j+1;
		std::cout << "Imie: " << stru[j].name << std::endl;
		std::cout << "Wiek: " << stru[j].age << std::endl;
		std::cout << "Numer indeksu: " << stru[j].index << std::endl;
		std::cout << "Wartosc srednia wszystkich ocen: " << (stru[j].course.physics+stru[j].course.chemistry)/2;
		
		std::cout << "Pola struktury:" << std::endl;
		std::cout << stru[j].name << " " << stru[j].name << " "<< stru[j].name << " "<< stru[j].name << " "<< stru[j].name;
	}
}