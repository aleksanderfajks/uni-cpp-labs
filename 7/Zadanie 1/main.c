#include <stdio.h>
#include <stdlib.h>

int bss1 = 0;
int data1 = 153;
int const roData1 = 120;

int main() {
	
	int x1=1, x2=2, x3=3, x4=4;
	printf("Adresy zmiennych alokowanych na stosie:\n");
	printf("&x1 - %#x \n", &x1);
	printf("&x2 - %#x \n", &x2);
	printf("&x3 - %#x \n", &x3);
	printf("&x4 - %#x \n", &x4);
	
	int *px1 = (int*) malloc(sizeof(int));
	int *px2 = (int*) malloc(sizeof(int));
	int *px3 = (int*) malloc(sizeof(int));
	int *px4 = (int*) malloc(sizeof(int));
	
	printf("Adresy zmiennych alokowanych na stercie:\n");
	printf("&px1 - %#x \n", px1);
	printf("&px2 - %#x \n", px2);
	printf("&px3 - %#x \n", px3);
	printf("&px4 - %#x \n", px4);
	
	free(px1);
	free(px2);
	free(px3);
	free(px4);
	
	printf("Adres zmiennej alokowanej na segmencie .bss:\n");
	printf("&bss1 - %#x \n", &bss1);
	printf("Adres zmiennej alokowanej na segmencie .data:\n");
	printf("&data1 - %#x \n", &data1);
	printf("Adres zmiennej alokowanej na segmencie .rodata:\n");
	printf("&roData1 - %#x \n", &roData1);
	printf("Adres zmiennej alokowanej na segmencie text(code):\n");
	printf("main - %#x \n", &main);

	
	return 0;
}

//Po uruchomieniu programu możemy zauważyć że zmienne na stosie są położone wyżej w przestrzeni adresowej niż zmienne na stercie.
// Tak, możliwe jest teoretyczne nałożenie się stosu i sterty.