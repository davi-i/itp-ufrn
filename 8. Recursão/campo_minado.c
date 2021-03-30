#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char imprimir;
	int bombas;    // quantidade de bombas vizinhas, 9 se a bomba for no tile
} Tile;

void imprimir_mapa(Tile** mapa, int altura, int largura){
	for (int i = 0; i < largura + 2; i++)
		printf("=");
	printf("\n");
	for (int i = 1; i <= altura; i++){
		for (int j = 1; j <= largura; j++)
			printf("%c", mapa[i][j].imprimir);
		printf("\n");
	}
}

int revelar_posicao(Tile** mapa, int x, int y, int altura, int largura){
	if (x > altura || x <= 0 || y > largura || y <= 0)
		return 0;

	if (mapa[x][y].bombas == 9){
		mapa[x][y].imprimir = 'X';
		return 1;
	}

	if (mapa[x][y].bombas == 0 && mapa[x][y].imprimir == '*') {
		mapa[x][y].imprimir = '0';
		revelar_posicao(mapa, x - 1, y - 1, altura, largura);
		revelar_posicao(mapa, x - 1, y    , altura, largura);
		revelar_posicao(mapa, x - 1, y + 1, altura, largura);
		revelar_posicao(mapa, x    , y - 1, altura, largura);
		revelar_posicao(mapa, x    , y + 1, altura, largura);
		revelar_posicao(mapa, x + 1, y - 1, altura, largura);
		revelar_posicao(mapa, x + 1, y    , altura, largura);
		revelar_posicao(mapa, x + 1, y + 1, altura, largura);
		return 0;
	}

	mapa[x][y].imprimir = mapa[x][y].bombas + '0'; // converte de inteiro pra char
	
	return 0;
}

void revelar_mapa (Tile** mapa, int altura, int largura){
	for (int i = 1; i <= altura; i++){
		for (int j = 1; j <= largura; j++){
			if (mapa[i][j].imprimir == '*'){
				if (mapa[i][j].bombas == 9)
					mapa[i][j].imprimir = 'B';
				else
					mapa[i][j].imprimir = mapa[i][j].bombas + '0';
			}
		}
	}
}

void adicionar_bomba(Tile** mapa, int x, int y){
	mapa[x][y].bombas++;
	if (mapa[x][y].bombas >= 10)
		mapa[x][y].bombas = 9; // o número de bombas não pode passar de 9
}

int main(){
	int altura, largura;  
	int n_bombas;
	int jogadas;
	int morreu = 0;
	Tile** mapa;

	scanf("%d %d", &altura, &largura);
	scanf("%d", &n_bombas);

	mapa = malloc(sizeof(Tile*) * (altura + 2));
	for (int i = 0; i < altura + 2; i++){
		mapa[i] = malloc(sizeof(Tile) * (largura + 2));
		for (int j = 0; j < largura + 2; j++) {
			mapa[i][j].imprimir = '*';
			mapa[i][j].bombas = 0; 
		}	
	}

	for (int i = 0; i < n_bombas; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		mapa[x][y].bombas = 9;
		adicionar_bomba(mapa, x - 1, y - 1);
		adicionar_bomba(mapa, x - 1, y    );
		adicionar_bomba(mapa, x - 1, y + 1);
		adicionar_bomba(mapa, x    , y - 1);
		adicionar_bomba(mapa, x    , y + 1);
		adicionar_bomba(mapa, x + 1, y - 1);
		adicionar_bomba(mapa, x + 1, y    );
		adicionar_bomba(mapa, x + 1, y + 1);
	}

	scanf("%d", &jogadas);

	for (int i = 0; i < jogadas; i++){
		char jogada[10];
		int x, y;
		scanf(" %s %d %d", jogada, &x, &y);

		if (strcmp(jogada, "Clica") == 0){
			morreu = revelar_posicao(mapa, x, y, altura, largura);
			if (morreu)
				break;
		} else if (strcmp(jogada, "Marca") == 0)
			mapa[x][y].imprimir = 'B';
		imprimir_mapa(mapa, altura, largura);
	}
	if (morreu) { 
		printf("CABUUUUM!\n");
		printf("Game Over....\n");
	} else
		printf("Você sobreviveu!\n");
	revelar_mapa(mapa, altura, largura);
	imprimir_mapa(mapa, altura, largura);

	return 0;
}