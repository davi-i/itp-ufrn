#include <stdio.h>

int main() {
    const int NOTAS[] = {100, 50, 20, 10, 5, 2};
    int valor;
    scanf("%d", &valor);

    for (int i = 0; i < 6; i++){
        int quantidade = valor / NOTAS[i];
        if (quantidade > 0){
            printf("%d nota(s) de %d\n", quantidade, NOTAS[i]);
            valor %= NOTAS[i];
        }
    }
    if (valor > 0){
        printf("%d moeda(s) de 1\n", valor);
    }

    return 0;
}