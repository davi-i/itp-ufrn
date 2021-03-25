#include <stdio.h>

int calcular_score(int score1, int score2, int score3){
	int aux;

	// Altera os valores de score1 e score2 para deixar
	// o menor entre os dois em score2
	if (score2 > score1){
		aux = score1;
		score1 = score2;
		score2 = aux;
	}

	// Altera os valores de score2 e score3 para deixar
	// o menor score (entre todos) em score3
	if (score3 > score2){
		aux = score2;
		score2 = score3;
		score3 = aux;
	}

	// Como score3 é o menor score entre os 3,
	// o menor entre score1 e score2 é o intermediário
	if (score2 > score1) return score1;

	return score2;
}

int main() {
	int scores_A[3], scores_B[3], score_final_A, score_final_B;
	int score1, score2, score3;

	for (int i = 0; i < 3; i++){
		scanf("%d %d %d", &score1, &score2, &score3);
		scores_A[i] = calcular_score(score1, score2, score3);
	}

	for (int i = 0; i < 3; i++){
		scanf("%d %d %d", &score1, &score2, &score3);
		scores_B[i] = calcular_score(score1, score2, score3);
	}

	score_final_A = calcular_score(scores_A[0], scores_A[1], scores_A[2]);
	score_final_B = calcular_score(scores_B[0], scores_B[1], scores_B[2]);

	if (score_final_A > score_final_B) printf("A\n");
	else if (score_final_B > score_final_A) printf("B\n");
	else printf("empate\n");

	return 0;
}