# include <stdio.h>
# include <stdlib.h>

int main(){
	printf("Otwarcie pliku.\n");
	FILE * fPtr = fopen ("input.txt", "w");
	
	if ( fPtr == NULL ) {
		printf ("Nie udalo sie otworzyc pliku.\n") ;
		exit ( EXIT_FAILURE ) ;
	}
	
	char tab[21];
	printf("Wpisz maksymalnie 20 znakow\n");
	for(int i=0; i<20; i++){
		
		fflush(stdin);
		scanf("%c", &tab[i]);
		if (tab[i]=='q' || tab[i]=='Q'){
			while(i<20){
				tab[++i]='\0';
			}
			break;
		} 
		
	}
	
	if (fputs(tab, fPtr) == EOF){
		printf("Nie udalo sie zapisac do pliku.\n");
		exit(EXIT_FAILURE);
	}
	if(fclose(fPtr)!=0) {
		printf("Nie udalo sie zamknac pliku.\n");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS ; 
}