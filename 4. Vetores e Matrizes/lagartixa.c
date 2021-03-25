#include <stdio.h>

int main(int argc, char const *argv[]) {
	int mapa_indisponivel[6][6] = {0};
	int M, x, Y;
	int i, j;
	
	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			char local;
			scanf(" %c", &local);
			switch (local){
				case '>': mapa_indisponivel[i][j + 1] = 1; break;
				case '<': mapa_indisponivel[i][j - 1] = 1; break;
				case '^': mapa_indisponivel[i - 1][j] = 1; break;
				case 'v': mapa_indisponivel[i + 1][j] = 1; break;
			}
		}
	}

	scanf("%d %d %d", &M, &x, &Y);
	x--;
	y--;

	for (i = 0; i < M; i++){
		char direcao;
		scanf(" %c", &direcao);
		switch (direcao){
			case 'D': Y++; break;
			case 'E': Y--; break;
			case 'C': x--; break;
			case 'B': x++; break;
		}
		if (x >= 6 || x < 0 || Y >= 6 || Y < 0) {
			printf("Movimento Invalido\n");
			break;
		}
		if (mapa_indisponivel[x][Y]){
			printf("Freeze!\n");
			break; 
		}
	}
	
	if (i == M) printf("Like a Ninja\n");
	
	return 0;
}