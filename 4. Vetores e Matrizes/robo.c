#include <stdio.h>

#define NORTE 0
#define LESTE 1
#define SUL 2
#define OESTE 3


int main() {
	int altura, largura;
	int robo_x, robo_y;
	int movimentos, direcao_num;
	char direcao;

	scanf("%d %d", &altura, &largura);

	char mapa[altura][largura];

	for (int i = 0; i < altura; i++)
		for (int j = 0; j < largura; j++)
			scanf(" %c", &mapa[i][j]);

	scanf("%d %d %c", &robo_y, &robo_x, &direcao);

	robo_x--;
	robo_y--;

	// Converte a direção em `char` para uma
	// direção em `int`, pois é mais fácil
	// virar a direita (+1) ou a esquerda (-1)
	switch (direcao){
		case 'N': direcao_num = NORTE; break;
		case 'L': direcao_num = LESTE; break;
		case 'S': direcao_num = SUL; break;
		case 'O': direcao_num = OESTE; break;
	}

	scanf("%d", &movimentos);

	while (movimentos > 0){
		int x, y;

		// Concerta a direção caso ela seja
		// maior que 3 ou menor que 0
		direcao_num += 4; 
		direcao_num %= 4;

		switch (direcao_num){
			case NORTE:
				x = robo_x;
				y = robo_y - 1;
				break;
			case LESTE:
				x = robo_x + 1;
				y = robo_y;
				break;
			case SUL:
				x = robo_x;
				y = robo_y + 1;
				break;
			case OESTE:
				x = robo_x - 1;
				y = robo_y;
				break;
		}

		if (x < 0 || x >= largura || y < 0 || y >= altura)
			direcao_num++;
		else {
			switch (mapa[y][x]){
				case '.':
					robo_x = x;
					robo_y = y;
					break;
				case '*':
					direcao_num--;
					break;
				case '|':
				case '_':
					direcao_num++;
			}
		}
		movimentos--;
	}
	printf("Posição final: %d %d\n", robo_y + 1, robo_x + 1);
	return 0;
}