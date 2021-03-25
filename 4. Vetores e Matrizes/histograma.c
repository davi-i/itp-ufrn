#include <stdio.h>

/**
 * Cria um histograma H com C categorias a partir de uma sequência de valores lidos da entrada-padrão.
 * A entrada a ser lida contém um valor inteiro N seguido de uma sequência de N valores reais.
 * 
 * Os valores lidos estarão entre na faixa de 0 a 10 (incluindo estes) e serão contabilizados no histograma
 * de acordo com o intervalo a qual pertence, levando em conta que haverá C categorias entre 0 e 10.
 * 
 * Por exemplo, se C for 5, teremos os intervalos [0; 2[, [2; 4[, [4; 6[, [6; 8[ e [8; 10]. Portanto, se o
 * valor 3.0 for lido, a 2ª categoria terá um elemento a mais no histograma. Se C for 3, os intervalos
 * seriam [0; 3.333...[, [3.333...; 6.666...[ e [6.666...;10]. Portanto, a 1ª categoria será atualizada.
 * 
 * @param c Número de categorias do histograma
 * @param h Array do histograma cujos valores serão atualizados a partir de dados lidos da entrada-padrão.
 */
void createHistogram(int c, int h[c]) {
    int n_alunos;
    scanf("%d", &n_alunos);
    
    for (int i = 0; i < c; i++) h[i] = 0;

    for (int i = 0; i < n_alunos; i++){
        double nota;
        scanf("%lf", &nota);

        for (int j = c - 1; j >= 0; j--){
            printf("%lf\n", (10.0 / c)*j);
            if(nota >= (10 / c)*j){
                h[j]++;
                break;
            }

        }

    }
}

/**
 * Junta os valores de dois histogramas em um terceiro histograma.
 * 
 * @param c  Número de categorias do histograma.
 * @param h1 Array com os dados do 1º histograma.
 * @param h2 Array com os dados do 2º histograma.
 * @param joint Array do histograma cujos valores serão atualizados a partir dos dois primeiros.
 */
void joinHistograms(int c, int h1[c], int h2[c], int joint[c]) {
    for (int i = 0; i < c; i++){
        joint[i] = h1[i] + h2[i];
    }
}

/**
 * Imprime um histograma em modo textual. A altura do histograma (quantidade de linhas a
 * serem impressas) corresponde ao maior valor de seu array.
 * 
 * @param c Número de categorias do histograma.
 * @param h Array com os dados do histograma a imprimir.
 */
void printHistogram(int c, int h[c]) {
    int maior_quantidade = 0;

    for (int i = 0; i < c; i++){
        if (h[i] > maior_quantidade) maior_quantidade = h[i];
    }

    for (int i = maior_quantidade; i > 0; i--){
        for (int j = 0; j < c; j++){
            if (h[j] >= i) printf("_##_");
            else printf("____");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int numCateg;
    scanf("%i", &numCateg);

    int histA[numCateg];
    int histB[numCateg];
    int histAll[numCateg];

    createHistogram(numCateg, histA);
    createHistogram(numCateg, histB);
    joinHistograms(numCateg, histA, histB, histAll);

    printHistogram(numCateg, histA);
    printHistogram(numCateg, histB);
    printHistogram(numCateg, histAll);

    return 0;
}