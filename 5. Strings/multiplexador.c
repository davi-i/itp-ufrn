#include <stdio.h>
#include <string.h>

#define MAX 40

int main(){
	char A[MAX], B[MAX];
	int tamanho_A, tamanho_B, maior;

	fgets(A, MAX, stdin);
	fgets(B, MAX, stdin);

	tamanho_A = strlen(A) - 1;
	tamanho_B = strlen(B) - 1;

	A[tamanho_A] = '\0';
	B[tamanho_B] = '\0';

	maior = (tamanho_A > tamanho_B) ? tamanho_A : tamanho_B;

	for (int i = 0; i < maior; i++){
		if (i < tamanho_A) printf("%c", A[i]);
		if (i < tamanho_B) printf("%c", B[i]);
	}

	printf("\n");
	
	return 0;
}