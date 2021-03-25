#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum item{
  cura = 1,
  dinheiro,
  vigor
};

enum trap{
  buraco = 1,
  espinhos,
  ladrao
};

typedef struct person{
  int life, attack;
} Personagem;

typedef struct player{
  Personagem p; 

  int x, y, escudo, loot;
} Jogador;

typedef struct room{
  Personagem p;
  int tesouro;
  int armadilha;
} Sala;

Sala** cria_mapa(int lin, int col, Jogador* player){
	int n_inimigos, n_tesouros, n_armadilhas;
	int x, y;

	Sala** mapa = malloc(sizeof(Sala*) * lin);
	for (int i = 0; i < lin; i++)
		mapa[i] = calloc(sizeof(Sala), col);

	scanf(" (%d %d) - %d %d", &x, &y, &(player->p.life), &(player->p.attack));

	player->x = x - 1;
	player->y = y - 1;
	player->escudo = 0;
	player->loot = 0;

	scanf("%d %d %d", &n_inimigos, &n_tesouros, &n_armadilhas);

	for (int i = 0; i < n_inimigos; i++){
		scanf(" (%d %d)", &x, &y);
		x--;
		y--;
		scanf(" - %d %d", &mapa[x][y].p.life, &mapa[x][y].p.attack);
	}

	for (int i = 0; i < n_tesouros; i++){
		char nome[10];

		scanf("%s %d %d", nome, &x, &y);
		x--;
		y--;

		if (strcmp(nome, "dinheiro") == 0)
			mapa[x][y].tesouro = dinheiro;
		else if (strcmp(nome, "cura") == 0)
			mapa[x][y].tesouro = cura;
		else if (strcmp(nome, "escudo") == 0)
			mapa[x][y].tesouro = vigor;
	}

	for (int i = 0; i < n_armadilhas; i++){
		char nome[10];

		scanf("%s %d %d", nome, &x, &y);
		x--;
		y--;

		if (strcmp(nome, "espinhos") == 0)
			mapa[x][y].armadilha = espinhos;
		else if (strcmp(nome, "buraco") == 0)
			mapa[x][y].armadilha = buraco;
		else if (strcmp(nome, "ladrao") == 0)
			mapa[x][y].armadilha = ladrao;
	}

	printf("Mapa inicializado!\n");
	printf("Jogador na posicao %d,%d\n", player->x + 1, player->y + 1);

	return mapa;
}

void batalhar(Jogador* player, Personagem* inimigo) {
	int turno = 1;
	while(player->p.life > 0 && inimigo->life > 0) {
		if (turno % 2 == 1) {
			printf("Jogador ataca!\n");
			inimigo->life -= player->p.attack;
			if (inimigo->life <= 0)
				inimigo->life = 0;
			printf("Dano de %d\n", player->p.attack);
			printf("Vida do inimigo: %d\n", inimigo->life);
		} else {
			if (player->escudo){
				printf("Defendeu o golpe!\n");
				player->escudo = 0;
			} else {
				printf("Inimigo ataca!\n");
				player->p.life -= inimigo->attack;
				if (player->p.life <= 0)
					player->p.life = 0;
				printf("Dano de %d\n", inimigo->attack);
				printf("Vida do jogador: %d\n", player->p.life);
			}
		}
		turno++;
	}
}

int executa_passo(int n, int m, Sala** mapa, char step, Jogador* player){
	int x = player->x;
	int y = player->y;
	switch (step){
		case 'W': x--; break;
		case 'S': x++; break;
		case 'A': y--; break;
		case 'D': y++; break;
	}
	printf("Avancando para %d, %d...\n", x + 1, y + 1);
	
	if (x >= n || x < 0 || y >= m || y < 0){
		printf("Movimento Ilegal!\n");
		return 1;
	}

	player->x = x;
	player->y = y;

	if (mapa[x][y].p.life > 0) {
		printf("Um inimigo!!!\n");
		batalhar(player, &(mapa[x][y].p));
	}

	if (mapa[x][y].tesouro > 0){
		printf("Um tesouro!\n");
		switch (mapa[x][y].tesouro){
			case cura:
				printf("Jogador coleta: pocao de cura!\n");
				player->p.life += 10;
				break;
			case dinheiro:
				printf("Jogador coleta: dinheiro!\n");
				player->loot += 10;
				break;
			case vigor:
				printf("Jogador coleta: um escudo!\n");
				player->escudo = 1;
				break;
		}
	}

	if (mapa[x][y].armadilha > 0){
		switch (mapa[x][y].armadilha){
			case buraco:
				printf("Armadilha: buraco! Jogador se machuca!\n");
				player->p.life -= 10;
				break;
			case espinhos:
				printf("Armadilha: espinhos! Jogador se machuca!\n");
				player->p.life -= 5;
				break;
			case ladrao:
				printf("Armadilha: ladrao! Jogador perde dinheiro!\n");
				player->loot -= 10;
				if (player->loot < 0)
					player->loot = 0;
				break;
		}
	}

	if (player->p.life <= 0){
		player->p.life = 0;
		return -1;
	}
	return 1;
}

void imprime_status_personagem(Jogador p){
	printf("Terminou na posicao (%d, %d)\n", p.x + 1, p.y + 1);
	printf("Vida: %d\n", p.p.life);
	printf("Dinheiro: %d\n", p.loot);
}

int main(){
  int n, m, movimentos, res;
  char passo;
  Jogador player;
  Sala** mapa;

  scanf("%d %d", &n, &m);

  mapa = cria_mapa(n, m, &player);

  scanf("%d", &movimentos);

  for(int i = 0; i < movimentos; i++){
    scanf(" %c", &passo);

    res = executa_passo(n, m, mapa, passo, &player);
    if(res == -1) break;
  }
 
  res < 0 ? printf("You died...\n"): printf("Vitoria!\n");

  imprime_status_personagem(player);

  for (int i = 0; i < n; i++)
  	free(mapa[i]);

  free(mapa);

  return 0;
}