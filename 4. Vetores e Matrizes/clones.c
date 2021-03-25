#include <stdio.h>

int main() {
	int largura, altura;
	int jedi_x, jedi_y;
	int jedi_atingido = 0;
	int n_bombas = 0;

	scanf("%d %d", &altura, &largura);
	scanf("%d %d", &jedi_x, &jedi_y);

	altura += 2;
	largura += 2;

	int mapa[altura][largura];

	for (int i = 0; i < altura; i++){
		mapa[i][0] = 0;
		mapa[i][largura - 1] = 0;
	}

	for (int j = 1; j < largura - 1; j++){
		mapa[0][j] = 0;
		mapa[altura - 1][j] = 0;
	}

	for (int i = 1; i < altura - 1; i++)
		for (int j = 1; j < largura - 1; j++)
			scanf("%d", &mapa[i][j]);

	for (int i = 1; i < altura - 1; i++){
		for (int j = 1; j < largura - 1; j++){
			if (mapa[i][j] <= mapa[i - 1][j - 1]) continue;
			if (mapa[i][j] <= mapa[i - 1][j]) continue;
			if (mapa[i][j] <= mapa[i - 1][j + 1]) continue;
			if (mapa[i][j] <= mapa[i][j - 1]) continue;
			if (mapa[i][j] <= mapa[i][j + 1]) continue;
			if (mapa[i][j] <= mapa[i + 1][j - 1]) continue;
			if (mapa[i][j] <= mapa[i + 1][j]) continue;
			if (mapa[i][j] <= mapa[i + 1][j + 1]) continue;

			printf("Local %d: %d %d\n", ++n_bombas, i, j);
			if(i == jedi_x && j == jedi_y)
				jedi_atingido = 1;
		}
	}

	if (jedi_atingido) printf("Descanse na Força...\n");
	else printf("Ao resgate!\n");

	return 0;
}