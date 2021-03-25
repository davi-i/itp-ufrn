#include <stdio.h>
#include <math.h>

double distancia(double x1, double y1, double x2, double y2){
	return sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));
}

int pontuacao_lancamento(double distancia_centro, double distancia_anterior){
	int pontuacao = 0;
	
	if (distancia_centro <= 1) pontuacao += 10;
	else if (distancia_centro <= 2) pontuacao += 6;
	else if (distancia_centro <= 3) pontuacao += 4;

	if (distancia_anterior <= 1) pontuacao += 5;
	else if (distancia_anterior <= 2) pontuacao += 3;
	else if (distancia_anterior <= 3) pontuacao += 2;

	return pontuacao;
}

int main() {
	// distancia_anterior começa com o valor 4 para o jogador
	// não ganhar pontos bônus no primeiro lançamento
	double x, y, x_anterior, y_anterior, distancia_anterior=4;
	int pontuacao = 0, primeiro = 1;

	for (int i = 0; i < 10; i++) {
		scanf("%lf %lf", &x, &y);

		if (primeiro == 1) primeiro = 0;
		else distancia_anterior = distancia(x, y, x_anterior, y_anterior);

		pontuacao += pontuacao_lancamento(distancia(x, y, 0, 0), distancia_anterior);

		x_anterior = x;
		y_anterior = y;
	}
	printf("%d\n", pontuacao);
	
	return 0;
}