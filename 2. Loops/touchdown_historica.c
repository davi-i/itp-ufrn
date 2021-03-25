#include <stdio.h>
 
int main() {
    int dados_totais[3][2] = {{0}}, pontos[2], jogos;
    char nome_dados[3][13] = {"Touch Downs", "Field Goals", "Pontos Extras"};

    scanf("%d", &jogos);

    for (int i = 0; i < jogos; i++){
        int dados[3][2], time = 0;
        for (int j = 0; j < 3; j++){
            if (j >= 2 && time == 0){
                j = 0;
                time = 1;
            }
            scanf(" %d", &dados[j][time]);
            dados_totais[j][time] += dados[j][time];
        }
    }
    
    pontos[0] = dados_totais[0][0] * 6 + dados_totais[1][0] * 3 + dados_totais[2][0];
    pontos[1] = dados_totais[0][1] * 6 + dados_totais[1][1] * 3 + dados_totais[2][1];
    
    if (pontos[0] > pontos[1]){
        printf("Saints é o campeão na série histórica!\n");
        printf("Placar: %d x %d\n", pontos[0], pontos[1]);
    } else if (pontos[0] < pontos[1]){
        printf("Bucaneers é o campeão na série histórica!\n");
        printf("Placar: %d x %d\n", pontos[1], pontos[0]);
    } else{
        printf("Série histórica empatada em %d pontos!\n", pontos[0]);
    }

    for (int i = 0; i < 3; i++){
        if (dados_totais[i][0] > dados_totais[i][1]){
            printf("Saints marcou mais %s(%d)\n", nome_dados[i], dados_totais[i][0]);
        } else if (dados_totais[i][0] < dados_totais[i][1]){
            printf("Bucaneers marcou mais %s(%d)\n", nome_dados[i], dados_totais[i][1]);
        } else{
            printf("Número de %s empatado(%d)\n", nome_dados[i], dados_totais[i][0]);
        }
    }

    return 0;
}