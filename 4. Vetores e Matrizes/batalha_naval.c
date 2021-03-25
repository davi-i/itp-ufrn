#include <stdio.h>

int main() {
	char mapa[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			mapa[i][j] = '~';

	for (int tamanho = 1; tamanho <= 4; tamanho++){
		int x, y, primeiro_x, primeiro_y;
		char corpo, fim = '*';

		for (int posicao = 1; posicao <= tamanho; posicao++){
			scanf("%d %d", &x, &y);

			if (posicao == 1) {
				primeiro_x = x;
				primeiro_y = y;
				continue;
			} else if (posicao == 2){
				if (primeiro_x == x){
					corpo = '=';
					fim = '>';
					mapa[primeiro_x][primeiro_y] = '<';
				}
				else {
					corpo = '|';
					fim = 'v';
					mapa[primeiro_x][primeiro_y] = '^';
				}
			}
			mapa[x][y] = corpo;
		}
		mapa[x][y] = fim;
	}
	
	for (int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++)
			printf("%c", mapa[i][j]);
		printf("\n");
	}

	return 0;
}