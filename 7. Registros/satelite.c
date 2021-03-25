#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 300

typedef struct {
	unsigned *array;
	unsigned size;
} IntArray;

typedef struct {
	IntArray integer;
	IntArray fractional;
	unsigned exp;
	int signal;
} BigFloat;

void readline(char line[MAX_LINE]){
	fgets(line, MAX_LINE, stdin);
	if (line[strlen(line) - 1] == '\n') 
		line[strlen(line) - 1] = '\0';
}

IntArray strToIntArray(char str[MAX_LINE]){
	IntArray intarray;
	int cont = 0;
	intarray.size = strlen(str) == 0? 1 : (strlen(str) - 1) / 9 + 1;
	intarray.array = malloc(sizeof(unsigned) * intarray.size);

	while (strlen(str) > 9){
		char *piece = str + (strlen(str) - 9);
		intarray.array[cont] = atoi(piece);
		piece[0] = '\0';
		cont++;
	}
	intarray.array[cont] = atoi(str);

	return intarray;
}

BigFloat strToBigFloat(char line[MAX_LINE]){
	BigFloat number;
	char *piece;
	int cont_0 = 0, pos;

	if (line[0] == '-'){
		number.signal = -1;
		line++;
	} else
		number.signal = 1;

	if (line[strlen(line) - 1] == '.')
		strcat(line, "0");

	piece = strtok(line, ".");
	
	if (line[0] == '.'){
		number.integer.size = 1;
		number.integer.array = malloc(sizeof(unsigned));
		number.integer.array[0] = 0;
	} else {
		number.integer = strToIntArray(piece);
		piece = strtok(NULL, ".");
	}

	pos = strlen(piece) - 1;
	while (piece[pos] == '0'){
		piece[pos] = '\0';
		pos--;
	}

	while (piece[cont_0] == '0')
		cont_0++;
	number.exp = cont_0;

	number.fractional = strToIntArray(piece);

	return number;
}

void printIntArray(IntArray *intarray){
	printf("%u", intarray->array[intarray->size - 1]);
	
	for (int i = intarray->size - 2; i >= 0; i--)
		printf("%09u", intarray->array[i]);
}

void printBigFloat(BigFloat number){
	if (number.signal == -1)
		printf("-");
	
	printIntArray(&(number.integer));
	
	printf(".");
	for (unsigned i = 0; i < number.exp; i++)
		printf("0");
	printIntArray(&(number.fractional));

	printf("\n");
}

int main() {
    char line[MAX_LINE];
    readline(line);
    BigFloat bf = strToBigFloat(line);
    printBigFloat(bf);
    printf("%i %u %u %u\n",
        bf.signal,
        bf.exp,
        bf.integer.array[bf.integer.size - 1],
        bf.fractional.array[bf.fractional.size - 1]
    );
    return 0;
}
