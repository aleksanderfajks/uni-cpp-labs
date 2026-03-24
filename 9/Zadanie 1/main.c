//Zadanie 1

# include <stdio.h>
# include <stdbool.h>

bool median(const int * tab , unsigned int n , float * buffer );
void bubbleSort(const int * tab, unsigned int n);


int main (){
	const int tab1[] = {3 , -1 , 2 , 5 , -7 , 0 , 2};
	const int tab2[] = {2, 11, -5, 1, 4, 9};
	float mediana;
	
	if(median(tab1, sizeof(tab1)/sizeof(int), &mediana)){
		printf("Mediana pierwszej tablicy = %f\n", mediana);
	} else {
		printf("Blad w obliczaniu mediany. \n");
	}
	
	if(median(tab2, sizeof(tab2)/sizeof(int), &mediana)){
		printf("Mediana drugiej tablicy = %f\n", mediana);
	} else {
		printf("Blad w obliczaniu mediany. \n");
	}
	
	bubbleSort(tab1, sizeof(tab1)/sizeof(int));
	bubbleSort(tab2, sizeof(tab2)/sizeof(int));
	
	return 0;
}

bool median(const int * tab , unsigned int n , float * buffer ) {
	bool result = false;
	if (tab!= NULL && buffer!=NULL && n!=0) {
		
		//Tymczasowa kopia tablicy
		int kopia[n];
		for (int i=0; i<n; i++){
			kopia[i]=tab[i];
		}
		
		//Sortowanie bąbelkowe
		bubbleSort(tab1, sizeof(tab1)/sizeof(int));
		bubbleSort(tab2, sizeof(tab2)/sizeof(int));
		
		if(n%2==1){	//Mediana dla nieparzystej liczby elementów
			*buffer=kopia[n/2];
		} else {	//Mediana dla parzystej liczby elementów
			int x1=kopia[(n/2)-1];
			int x2=kopia[n/2];
			*buffer = (x1+x2)/2.0f;
		}
		
		result = true;
	}
	
	return result;
}

void bubbleSort(const int * tab, unsigned int n){
	int kopia[n];
	for (int i=0; i<n; i++){
		kopia[i]=tab[i];
	}
	
	for (unsigned int i=0; i<n-1; i++){
		for(unsigned int j=0; j<n-i-1; j++){
			if(kopia[j]>kopia[j+1]){
				int tmp=kopia[j];
				kopia[j]=kopia[j+1];
				kopia[j+1]=tmp;
			}
		}
	}
	
	printf("Tablica po sortowaniu babelkowym wygladala by nastepujaca:");
	for (int i=0; i<n; i++){
		printf(" %d", kopia[i]);
	}
	printf("\n");
}