#include <stdio.h>

int main() {
    int hora, minuto;
    scanf("%d:%d", &hora, &minuto);

    if (hora < 12 || (hora == 12 && minuto == 0)){
        printf("Cedo demais!\n");
    } else {
        printf("Hora de acordar...\n");
    }

    return 0;
}