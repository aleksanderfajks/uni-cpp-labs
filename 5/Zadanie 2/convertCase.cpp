#include <cstring>
#include "convertCase.h"

void convertCase(char text[]){
	for(int i=0; i<strlen(text); i++){
		if(text[i]>64 && text[i]<91){
			text[i]=text[i]+32;
		} else if(text[i]>96 && text[i]<123){
			text[i]=text[i]-32;
		} else if(text[i]==46){
			text[i]=33;
		}
	}
}