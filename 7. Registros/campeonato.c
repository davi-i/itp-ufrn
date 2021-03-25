#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[201];
	int vitorias, empates, derrotas;
	int gols_feitos, gols_sofridos;
} Time;

void ler_times(Time *times, int quant){
	for (int i = 0; i < quant; i++){
		scanf("\n%[^;]; %d %d %d %d %d",
			  times[i].nome,
			  &times[i].vitorias,
			  &times[i].empates,
			  &times[i].derrotas,
			  &times[i].gols_feitos,
			  &times[i].gols_sofridos);
	}
}

int pontos(Time *time){
	return 3 * time->vitorias + time->empates;
}

int total_de_partidas(Time *time){
	return time->vitorias + time->empates + time->derrotas;
}

int saldo_de_gols(Time *time){
	return time->gols_feitos - time->gols_sofridos;
}

//Bubblesort no vetor
void ordenar_times(Time* times, int quant){
    Time aux;
    for (int i = 0; i < quant - 1; i++){
        for (int j = i + 1; j < quant; j++){
            if (pontos(&times[i]) < pontos(&times[j])){
                aux = times[i];
                times[i] = times[j];
                times[j] = aux;
            } else if (pontos(&times[i]) == pontos(&times[j])){
            	if (times[i].vitorias < times[j].vitorias){
	                aux = times[i];
	                times[i] = times[j];
	                times[j] = aux;
            	} else if (times[i].vitorias == times[j].vitorias){
	                if (saldo_de_gols(&times[i]) < saldo_de_gols(&times[j])){
		                aux = times[i];
		                times[i] = times[j];
		                times[j] = aux;
		            }
            	}
            }
        }
    }
}

void imprimir_tabela(Time* times, int quant){
	ordenar_times(times, quant);
	printf("Tabela do campeonato:\n");
	printf("Nome| Pontos| Jogos| Vitorias| Empates| Derrotas| Gols Pro| Gols Contra| Saldo de Gols\n");
	for (int i = 0; i < quant; i++){
		printf("%s|", times[i].nome);
		printf(" %d|", pontos(&times[i]));
		printf(" %d|", total_de_partidas(&times[i]));
		printf(" %d|", times[i].vitorias);
		printf(" %d|", times[i].empates);
		printf(" %d|", times[i].derrotas);
		printf(" %d|", times[i].gols_feitos);
		printf(" %d|", times[i].gols_sofridos);
		printf(" %d\n", saldo_de_gols(&times[i]));
	}
	printf("\n");
}

int main(){
	Time *times;
	int quant;

	scanf("%d", &quant);

	// printf("te peguei\n");

	times = malloc(sizeof(Time) * quant);

	ler_times(times, quant);
	imprimir_tabela(times, quant);

	printf("Times na zona da libertadores:\n");
	for (int i = 0; i < 6; i++)
		printf("%s\n", times[i].nome);
	printf("\n");

	printf("Times rebaixados:\n");
	for (int i = quant - 1; i >= quant - 4; i--)
		printf("%s\n", times[i].nome);
	printf("\n");

	free(times);
	return 0;
}