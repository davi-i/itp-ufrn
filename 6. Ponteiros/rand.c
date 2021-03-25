#include <stdio.h>
#include <stdlib.h>

/*
@brief gera um número aleatório no intervalo [min,max]
@param min o número minimo no range
@param max o número máximo no range
@return um número aleatório no intervalo [min,max]
*/
int rand_int_range(int min, int max){
   int range = max - min + 1;
   return min + rand()%range;
}

int *criarVetorAleatorio(int tamanho, int minimo, int maximo){
   int *vetor = malloc(sizeof(int) * (tamanho + 3));
   vetor[0] = tamanho;
   vetor[1] = minimo;
   vetor[2] = maximo;

   for (int i = 3; i < tamanho + 3; i++)
      vetor[i] = rand_int_range(minimo, maximo);

   return vetor;
}

int *criarHistograma(int *valores){
   int quantidade = valores[2] - valores[1] + 1;
   int *histograma = malloc(sizeof(int) * (quantidade + 2));
   histograma[0] = valores[1];
   histograma[1] = valores[2];

   for (int i = histograma[0]; i <= histograma[1]; i++){
      for (int j = 3; j < valores[0] + 3; j++){
         if (valores[j] == i){
            histograma[i - histograma[0] + 2]++;
         }
      }
   }

   return histograma;
}

float *criarPorcentagens(int *histograma){
   int quantidade = histograma[1] - histograma[0] + 1;
   int tamanho = 0;
   float *porcentagens = malloc(sizeof(float) * (quantidade));
   
   for (int i = 2; i < quantidade + 2; i++)
      tamanho += histograma[i];

   for (int i = 0; i < quantidade; i++)
      porcentagens[i] = (float)histograma[i + 2]/tamanho * 100;

   return porcentagens;
}

void imprimePorcentagens(float *porcentagens, int *histograma){
   printf("Valor |Qtdade |Porcent\n");
   for (int i = 0; i < histograma[1] - histograma[0] + 1; i++)
      printf("%d |%d |%.2f%%\n", histograma[0] + i, histograma[i + 2], porcentagens[i]);
}

void liberar(int *valores, float *porcentagens, int *histograma){
   free(valores);
   free(porcentagens);
   free(histograma);
}

int main(){
   int tamanho, maximo, minimo;
   scanf("%d", &tamanho);
   scanf("%d %d", &minimo, &maximo);
   int *valores = criarVetorAleatorio(tamanho, minimo, maximo);
   int *histograma = criarHistograma(valores);
   float *porcentagens = criarPorcentagens(histograma);
   imprimePorcentagens(porcentagens, histograma);
   liberar(valores, porcentagens, histograma);
   return 0;
}