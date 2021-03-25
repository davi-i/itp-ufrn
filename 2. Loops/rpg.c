#include <stdio.h>

int main() {
	int jogadas, dano_total;
	char *utlimo_ataque;
	scanf("%d %d", &jogadas, &dano_total);
	for (int i = 0; i < jogadas; i++){
		char jogador;
		int ataque;
		scanf(" %c %d", &jogador, &ataque);

		if (ataque <= 14) continue;

		switch (jogador){
			case 'A':
				utlimo_ataque = "Alyson";
				dano_total -= 10;
				break;
			case 'I':
				utlimo_ataque = "Isaac";
				dano_total -= 10;
				break;
			case 'R':
				utlimo_ataque = "Rafaela";
				dano_total -= 6;
				break;
			case 'W':
				utlimo_ataque = "Wellington";
				dano_total -= 8;
				break;
			case 'S':
				utlimo_ataque = "Salgado";
				dano_total -= 4;
				break;
			case 'C':
				utlimo_ataque = "Careca";
				dano_total -= 1;
				break;
		}
		if (dano_total <= 0){
			printf("%s derrotou o dragão!\n", utlimo_ataque);
			return 0;
		}
	}
	printf("Casa caiu!\n");
	return 0;
}