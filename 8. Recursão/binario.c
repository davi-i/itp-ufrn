#include <stdio.h>

void imprimir_em_binario(int numero){
	if (numero == 0 || numero == 1){
		printf("%d", numero);
		return;
	}

	imprimir_em_binario(numero / 2);
	printf("%d", numero % 2);
}

int main(){
	int numero;
	scanf("%d", &numero);
	imprimir_em_binario(numero);
	return 0;
}