#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adicionarLinhas(int N, char *linhas[N], char str[10]){
	for (int i = 0; i < N; i++) {
		if (linhas[i] == NULL){
			linhas[i] = malloc(sizeof(char) * (strlen(str) + 1));
			strcpy(linhas[i], str);
			return 1;
		} 
		int tamanho = strlen(linhas[i]);
		if (linhas[i][tamanho - 1] != '\n'){
			linhas[i] = realloc(linhas[i], sizeof(char) * (tamanho + strlen(str) + 1));
			strcat(linhas[i], str);
			return 1;
		}
	}
	return 0;
}

void imprimirLinhas(int N, char *linhas[N]){
	for (int i = 0; i < N; i++)
		printf("%s", linhas[i]);
}

void liberarLinhas(int N, char *linhas[N]){
	for (int i = 0; i < N; i++)
		free(linhas[i]);
}

int main(){
  char str[10];
  int N;   
  scanf("%d\n", &N);
  char *linhas[N];
  
  for (int i = 0; i < N; i++)
    linhas[i] = NULL;   
  
  do {
    fgets(str, 10, stdin);
  } while (adicionarLinhas(N, linhas, str));

  printf("Texto liberado pelo Ministro\n");
  imprimirLinhas(N, linhas);
  
  liberarLinhas(N, linhas);
  return 0;
}