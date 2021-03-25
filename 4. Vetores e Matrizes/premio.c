#include <stdio.h>

int main() {
	int n_simbolos, n_amigos, primeiro = 1;
	scanf("%d %d", &n_simbolos, &n_amigos);

	int simbolos[n_simbolos];

	for (int i = 0; i < n_simbolos; i++) simbolos[i] = 0;

	for (int i = 0; i < n_amigos; i++){
		int n_simbolos_amigo;
		scanf("%d", &n_simbolos_amigo);

		for (int j = 0; j < n_simbolos_amigo; j++){
			int simbolo;
			scanf("%d", &simbolo);
			simbolos[simbolo] = 1;
		}
	}

	printf("[");
	for (int i = 0; i < n_simbolos; i++){
		if (simbolos[i] == 0){
			if (primeiro == 0) printf(",");
			else primeiro = 0;
			printf(" %d", i);
		}
	}
	printf(" ]\n");
	return 0;
}