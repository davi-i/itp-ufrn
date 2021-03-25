#include <stdio.h>
#include <stdlib.h>
 
int main() {
    long hashmat, opponent;
    while (scanf("%ld %ld", &hashmat, &opponent) != EOF)
    	printf("%ld\n", labs(hashmat - opponent));
    return 0;
}