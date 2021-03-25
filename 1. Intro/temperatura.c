#include <stdio.h>
 
int main() {
    float temperatura, c, f, k;
    char escala;
    
    scanf("%f %c", &temperatura, &escala);

    if (escala == 'C'){
    	c = temperatura;
    	f = c * 1.8 + 32;
    	k = c + 273.15;
    } else if (escala == 'F'){
    	f = temperatura;
    	c = (f - 32)/1.8;
    	k = c + 273.15;
    } else if (escala == 'K'){
    	k = temperatura;
    	c = k - 273.15;
    	f = c * 1.8 + 32;
    }

    printf("Celsius: %.2f\n", c);
    printf("Farenheit: %.2f\n", f);
    printf("Kelvin: %.2f\n", k);

    return 0;
}