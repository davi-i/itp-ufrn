#include <stdio.h>
 
int main() {
    int TD[2], FG[2], PAT[2], pontos[2];
    
    scanf("%d %d %d", &TD[0], &FG[0], &PAT[0]);
    scanf("%d %d %d", &TD[1], &FG[1], &PAT[1]);
    
    pontos[0] = TD[0] * 6 + FG[0] * 3 + PAT[0];
    pontos[1] = TD[1] * 6 + FG[1] * 3 + PAT[1];
    
    printf("Placar: Saints %d x %d Bucaneers\n", pontos[0], pontos[1]);
    
    if (pontos[0] > pontos[1]){
        printf("Saints venceu!\n");
    } else if (pontos[0] < pontos[1]){
        printf("Bucaneers venceu!\n");
    } else{
        printf("Empate!");
    }
 
    return 0;
}