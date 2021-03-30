#include <stdio.h>

int mdc(int a, int b){
	if (b == 0)
		return a;

	return mdc(b, a % b);
}

int main(){
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	printf("MDC de %d, %d e %d: %d\n", a, b, c, mdc(mdc(a, b), c));
	return 0;
}