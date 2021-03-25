#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 60

int main(){
	char frase[MAX];
	int tamanho;

	fgets(frase, MAX, stdin);
	tamanho = strlen(frase) - 1;
	frase[tamanho] = '\0';

	frase[0] = toupper(frase[0]);
	for (int i = 1; i < tamanho; i++){
		if (frase[i - 1] == ' ')
			frase[i] = toupper(frase[i]);
		else
			frase[i] = tolower(frase[i]);
	}

	printf("%s\n", frase);

	return 0;
}