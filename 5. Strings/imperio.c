#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 200

const char S[] =
	{'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};

// Retorna a posição do caractere em S
// Se o caracte não pertencer a S, retorna -1
int posicao_S(char caractere){
	for (int i = 0; i < 40; i++)
		if (caractere == S[i])
			return i;

	return -1;
}

int descriptografar(char mensagem[MAX], int k[4]){
	int tamanho = strlen(mensagem);

	for (int i = 0; i < tamanho; i++){
		int posicao = posicao_S(mensagem[i]);
		if (posicao != -1) {
			posicao -= k[i % 4];
			posicao += 40; 
			posicao %= 40;

			mensagem[i] = S[posicao];
		} else {
			sprintf(mensagem, "Caractere invalido na entrada!");
			break;
		}
	}
}

int descobrir_chave(char mensagem[MAX], char fragmento[MAX], int k[4]){
	int tamanho = strlen(mensagem);

	for (int i = 0; i + 7 < tamanho; i++){
		int valido = 1;
		for (int j = 0; j < 4; j++){
			int diferenca1 = posicao_S(mensagem[j + i]) - posicao_S(fragmento[j]);
			int diferenca2 = posicao_S(mensagem[j + i + 4]) - posicao_S(fragmento[j + 4]);
			diferenca1 = (diferenca1 + 40) % 40;
			diferenca2 = (diferenca2 + 40) % 40;

			if (diferenca1 != diferenca2){
				valido = 0;
				break;
			}
			k[(i + j) % 4] = diferenca1;
		}
		if (valido)
			return 1;
	}
	return 0;
}

int main(){
	int k[4];
	char mensagem[MAX];
	char fragmento[MAX] = "QUE A FORCA ESTEJA COM VOCE";

	fgets(mensagem, MAX, stdin);
	mensagem[strlen(mensagem) - 1] = '\0';
	
	if (!descobrir_chave(mensagem, fragmento, k)){
		printf("Mensagem nao e da Resistencia!\n");
		return 0;
	}
	descriptografar(mensagem, k);

	for (int i = 0; i < 4; i++)
		printf("%d", k[i]);
	printf("\n%s\n", mensagem);

	return 0;
}