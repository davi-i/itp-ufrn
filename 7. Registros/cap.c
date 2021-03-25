#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id_cartela;
    int tam_cartela;
    int *numeros;
    int *marcacao;
} Cartela;

void inicializar_cartela(Cartela *cartela, int id, int tam_cartela, int tam_globo){
	int sorteados[tam_globo];
	memset(&sorteados, 0, sizeof(int) * tam_globo);

	cartela->id_cartela = id;
	cartela->tam_cartela = tam_cartela;
	cartela->numeros = malloc(sizeof(int) * tam_cartela);
	cartela->marcacao = calloc(tam_cartela, sizeof(int));

	srand(id);
	
	for (int i = 0; i < tam_cartela; i++){
		int sorteado = rand() % tam_globo + 1;
		if (sorteados[sorteado - 1] == 1){
			i--;
			continue;
		}
		cartela->numeros[i] = sorteado;
		sorteados[sorteado - 1] = 1;
	}
}

int marcar_numero(Cartela *cartela, int numero){
	int todos_marcados = 1;
	for (int i = 0; i < cartela->tam_cartela; i++){
		if (cartela->numeros[i] == numero)
			cartela->marcacao[i] = 1;
		else if (cartela->marcacao[i] == 0)
			todos_marcados = 0;
	}
	return todos_marcados;
}

int main(){
	int tam_cartela, tam_globo, semente;
	char entrada[20];
	Cartela* cartelas = NULL;
	int quant_cartelas = 0;

	scanf("%d %d %d\n", &tam_cartela, &tam_globo, &semente);

	int sorteados[tam_globo];
	memset(sorteados, 0, sizeof(int) * tam_globo);

	fgets(entrada, 20, stdin);
	while (strcmp(entrada, "Comecou o jogo!\n") != 0) {
		int id;
		Cartela cartela;
		
		sscanf(entrada, "%d", &id);
		inicializar_cartela(&cartela, id, tam_cartela, tam_globo);

		cartelas = realloc(cartelas, sizeof(Cartela) * (quant_cartelas + 1));
		cartelas[quant_cartelas] = cartela;

		quant_cartelas++;
		fgets(entrada, 20, stdin);
	}

	srand(semente);

	for (int i = 0; i < tam_globo; i++){
		int bingo = 0;
		int sorteado = rand() % tam_globo + 1;
		if (sorteados[sorteado - 1] == 1){
			i--;
			continue;
		}
		sorteados[sorteado - 1] = 1;
		printf("%d ", sorteado);
		for (int j = 0; j < quant_cartelas; j++){
			if (marcar_numero(&(cartelas[j]), sorteado)){
				printf("\nBingo! Cartela %d:", cartelas[j].id_cartela);
				for (int k = 0; k < cartelas[j].tam_cartela; k++)
					printf(" %d", cartelas[j].numeros[k]);
				printf("\n");
				bingo = 1;
				break;
			}
		}
		if (bingo)
			break;
	}

	for (int i = 0; i < quant_cartelas; i++){
		free(cartelas[i].numeros);
		free(cartelas[i].marcacao);
	}
	free(cartelas);

	return 0;
}