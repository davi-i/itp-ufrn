#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAVE 5940
#define MAX 501

char** separa(char str[MAX], int *quantidadeTextos){
  char **textoSeparado = NULL;
  char *texto = strtok(str, " ");
  int cont = 0;
  while(texto != NULL){
  	textoSeparado = realloc(textoSeparado, sizeof(char*) * (cont + 1));
    textoSeparado[cont] = texto;
    cont++;
    texto = strtok(NULL, " ");
  }
  *quantidadeTextos = cont;
  return textoSeparado;
}

char* juntar(char **vetor_strings, int tamanho_vetor){
  int tamanho_final = 0;
  char *strings_unidas;
  
  for (int i = 0; i < tamanho_vetor; ++i)
  	tamanho_final += strlen(vetor_strings[i]) + 1;

  strings_unidas = malloc(sizeof(char) * tamanho_final);

  strings_unidas[0] = '\0';
  for(int i = 0; i < tamanho_vetor; i++){
    strcat(strings_unidas, vetor_strings[i]);
    strcat(strings_unidas, " ");
  }

  return strings_unidas;
}

int tudo_maior_que_0(int* vetor, int tamanho){
	for (int i = 0; i < tamanho; i++)
		if (vetor[i] == 0)
			return 0;
	return 1;
}

char* embaralhar(char texto[MAX]){
	int n_palavras;
	char **palavras = separa(texto, &n_palavras);
	char **embaralhadas = malloc(sizeof(char*) * n_palavras);
	char *texto_embaralhado;
	int k = 0, usadas[n_palavras];
	
	memset(usadas, 0, sizeof(usadas));

	srand(CHAVE);

	do {
		int n = rand() % n_palavras;
		if (k >= n_palavras)
			embaralhadas = realloc(embaralhadas, sizeof(char*) * (k + 1));
		embaralhadas[k] = palavras[n];
		usadas[n]++;
		k++;
	} while (!tudo_maior_que_0(usadas, n_palavras));
	texto_embaralhado = juntar(embaralhadas, k);

	free(palavras);
	free(embaralhadas);
	return texto_embaralhado;
}

int main(){
	char texto[MAX], *texto_embaralhado;

	scanf("%[^\n]", texto);
	texto_embaralhado = embaralhar(texto);
	printf("%s\n",  texto_embaralhado);

	free(texto_embaralhado);

	return 0;
}