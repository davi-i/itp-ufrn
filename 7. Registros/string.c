#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char *str;
	int capacity;
	int length;
} string;

void set_str(string *output, char *input){
	output->length = strlen(input);
	output->capacity = (output->length / 16 + 1) * 16;
	output->str = malloc(sizeof(char) * output->capacity);
	strcpy(output->str, input);
}

void read_str(string *str){
	char* array = malloc(sizeof(char));
	strcpy(array, "");
	char aux[16];
	while(fgets(aux, 16, stdin) != NULL) {
		array = realloc(array, sizeof(char) * (strlen(array) + strlen(aux) + 1));
		strcat(array, aux);
	}
	if (array[strlen(array) - 1] == '\n')
		array[strlen(array) - 1] = '\0';
	set_str(str, array);
}

void concat_str(string *str1, string *str2){
	str1->length += str2->length;
	if (str1->length > str1->capacity){
		str1->capacity = (str1->length / 16 + 1) * 16;
		str1->str = realloc(str1->str, sizeof(char) * str1->capacity);
	}
	strcat(str1->str, str2->str);
}

void clear_str(string *str){
	free(str->str);
	str->str = NULL;
	str->capacity = 0;
	str->length = 0;
}

int main() {
    string greeting;
    string name;
    set_str(&greeting, "Oi ");
    read_str(&name);
    concat_str(&greeting, &name);
    printf("%s\n", greeting.str);
    printf("%i %i\n", greeting.capacity, greeting.length);
    clear_str(&greeting);
    clear_str(&name);
    return 0;
}
