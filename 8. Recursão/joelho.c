#include <stdio.h>
#include <stdlib.h>

typedef struct item {
	char nome[20];
	int valor;
	int peso;
	int escolhido;
} Item;

typedef struct inventario {
	int *indices;
	int valor_total;
	int quantidade;
} Inventario;

Item* combinacoes(int peso, int n_itens, Item itens[n_itens], Inventario* escolhidos, Inventario* melhor_inventario){
	for (int i = 0; i < n_itens; i++){
		if (itens[i].peso > peso)
			continue;

		if (itens[i].escolhido)
			continue;

		itens[i].escolhido = 1;
		escolhidos->indices[escolhidos->quantidade] = i;
		escolhidos->quantidade++;
		escolhidos->valor_total += itens[i].valor;

		combinacoes(peso - itens[i].peso, n_itens, itens, escolhidos, melhor_inventario);

		escolhidos->valor_total -= itens[i].valor;
		escolhidos->quantidade--;
		itens[i].escolhido = 0;
	}

	if (escolhidos->valor_total > melhor_inventario->valor_total){
		melhor_inventario->valor_total = escolhidos->valor_total;
		melhor_inventario->quantidade = escolhidos->quantidade;
		for (int i = 0; i  < escolhidos->quantidade; i++)
			melhor_inventario->indices[i] = escolhidos->indices[i];
	}
}

Inventario* inventario_vazio(int tamanho){
	Inventario* vazio = malloc(sizeof(Inventario));
	vazio->indices = malloc(sizeof(int) * tamanho);
	vazio->valor_total = 0;
	vazio->quantidade = 0;

	return vazio;
}

int main(){
	int n_itens, peso;

	scanf("%d %d", &n_itens, &peso);

	Item itens[n_itens];
	Inventario melhor_inventario = inventario_vazio(n_itens);

	for (int i = 0; i < n_itens; i++){
		scanf(" %s %d %d", &(itens[i].nome), &(itens[i].valor), &(itens[i].peso));
		itens[i].escolhido = 0;
	}

	combinacoes(peso, n_itens, itens, inventario_vazio(n_itens), melhor_inventario);

	if (melhor_inventario->quantidade == 0)
		printf("Nada para carregar...\n");
	else {
		printf("Inventario final:\n");
		for (int i = 0; i < melhor_inventario->quantidade; i++)
			printf("Item: %s\n", itens[melhor_inventario->indices[i]].nome);
		printf("Valor total: %d\n", melhor_inventario->valor_total);
	}
	return 0;
}