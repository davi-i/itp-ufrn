#include <stdio.h>
#include <math.h>

int main() {
 	char operacao;
 	double a, b;
 	int n;

 	do{
	 	scanf(" %c", &operacao);

	 	switch (operacao){
	 		case '+':
	 			scanf("%lf %lf", &a, &b);
	 			printf("%.3lf+%.3lf=%.3lf\n", a, b, a + b);
	 			break;
	 		case '-':
	 			scanf("%lf %lf", &a, &b);
	 			printf("%.3lf-%.3lf=%.3lf\n", a, b, a - b);
	 			break;
	 		case '*':
	 			scanf("%lf %lf", &a, &b);
	 			printf("%.3lf*%.3lf=%.3lf\n", a, b, a * b);
	 			break;
	 		case '/':
	 			scanf("%lf %lf", &a, &b);
	 			printf("%.3lf/%.3lf=%.3lf\n", a, b, a / b);
	 			break;
	 		case '^':
	 			scanf("%lf %d", &a, &n);
	 			printf("%.3lf^%d=%.3lf\n", a, n, round(pow(a, n)));
	 			break;
	 	}
 	} while(operacao != 'e');
	return 0;
}