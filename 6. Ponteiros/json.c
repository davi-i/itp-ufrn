#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 201

double *fromJsonString_double(char string[MAX], int *tam){
	char *valor;
	double *valores = NULL;
	int cont = 0;

	valor = strtok(string, "[, ]");
	while (valor != NULL){
		valores = realloc(valores, sizeof(double) * (cont + 1));
		valores[cont] = atof(valor);
		valor = strtok(NULL, "[, ]");
		cont++;
	}

	*tam = cont;

	return valores;
}

int *fromJsonString_int(char string[MAX], int *tam){
	char *valor;
	int *valores = NULL;
	int cont = 0;

	valor = strtok(string, "[, ]");
	while (valor != NULL){
		valores = realloc(valores, sizeof(int) * (cont + 1));
		valores[cont] = atoi(valor);
		valor = strtok(NULL, "[, ]");
		cont++;
	}

	*tam = cont;

	return valores;
}

int main(){
	int n, tam;
	char string[MAX];
	scanf("%d\n", &n);

	for (int i = 0; i < n; i++){
		int valor_e_double = 0, j;
		fgets(string, MAX, stdin);
		if (string[strlen(string) - 1] == '\n')
			string[strlen(string) - 1] = '\0';
		for (j = 0; j < (int)strlen(string); j++){
			printf("%c\n", string[j]);
			if (string[j] == '.'){
				valor_e_double = 1;
				break;
			}
		}
		if (valor_e_double){
			double *valores = fromJsonString_double(string, &tam);
			for (j = 0; j < tam; j++){
				if (j > 0)
					printf(" ");
				printf("%lf", valores[j]);
			}

		} else {
			int *valores = fromJsonString_int(string, &tam);
			for (j = 0; j < tam; j++){
				if (j > 0)
					printf(" ");
				printf("%d", valores[j]);
			}
		}
		if (j == 0)
			printf("vetor vazio\n");
		else
			printf("\n");
	}
}