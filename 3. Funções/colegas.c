#include <stdio.h>
#include <stdlib.h>

int soma_divisores(int num){
	int soma = 1;

	for (int i = 2; i <= num/2; i++){
		if (num % i == 0) soma += i;
	}

	return soma;
}

int sao_colegas(int num1, int num2){
	if (abs(soma_divisores(num1) - num2) <= 2 && abs(soma_divisores(num2) - num1) <= 2)
		return 1;
	return 0;
}

int main() {
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	if (sao_colegas(num1, num2)) printf("S\n");
	else printf("N\n");

	return 0;
}