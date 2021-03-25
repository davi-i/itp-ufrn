#include <stdio.h>
#include <string.h>

#define MAX 200

void criptografar(char mensagem[MAX], int k[4]){
	const char S[] =
		{'0','1','2','3','4','5','6','7','8','9',
	     'A','B','C','D','E','F','G','H','I','J',
	     'K','L','M','N','O','P','Q','R','S','T',
	     'U','V','W','X','Y','Z','.',',','?',' '};

	int tamanho = strlen(mensagem) - 1;
	mensagem[tamanho] = '\0';

	for (int i = 0; i < tamanho; i++){
		int invalido = 1;
		for (int j = 0; j < 40; j++){
			if (mensagem[i] == S[j]){
				int posicao = (j + k[i % 4]) % 40;
				mensagem[i] = S[posicao];
				invalido = 0;
				break;
			}
		}
		if (invalido){
			sprintf(mensagem, "Caractere invalido na entrada!");
			break;
		}
	}

}

int main(){
	int k[4];
	char sobra, mensagem[MAX];

	for (int i = 0; i < 4; i++)
		scanf("%1d", &k[i]);

	scanf("%c", &sobra);

	if (sobra != '\n'){
		printf("Chave invalida!");
	    return 0;
	}

	fgets(mensagem, MAX, stdin);
	criptografar(mensagem, k);

	printf("%s\n", mensagem);
	return 0;
}