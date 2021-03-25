#include <stdio.h>

int main() {
	int n_predios, maior_distancia = 0;

	scanf("%d", &n_predios);

	int n_andares[n_predios];

	for (int i = 0; i < n_predios; i++)
		scanf("%d", &n_andares[i]);

	for (int i = 0; i < n_predios - 1; i++){
		for (int j = i + 1; j < n_predios; j++){
			int distancia = n_andares[i] + (j - i) + n_andares[j];
			if (distancia > maior_distancia) maior_distancia = distancia;
		}
	}	

	printf("%d\n", maior_distancia);
	return 0;
}