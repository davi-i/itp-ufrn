#include <stdio.h>
#include <math.h>

int main() {
	int numero, primeiro = 1;

	scanf("%d", &numero);

	if (numero <= 1){
		printf("Erro, número precisa ser maior do que 1!\n");
		return 0;
	}

	// Laço que começa no 2 e depois vai pelos ímpares (possíveis primos)
	for (int i = 2; numero != 1 ; i += 2){
		int quantidade = 0;
		while (numero % i == 0) {
			quantidade++;
			numero /= i;
		}

		if (quantidade > 0){
			if (primeiro == 1) primeiro = 0;
			else printf("*");
			printf("%d^%d", i, quantidade);
		}
		// Consertar contador para iterar pelos ímpares
		if (i == 2) i--;
	}

	return 0;
}