#include <stdio.h>

void print_horario(int hora, int minuto, int segundo){
	minuto += segundo / 60;
	hora += minuto / 60;
	
	segundo %= 60;
	minuto %= 60;
	hora %= 24;

	printf("%02d:%02d:%02d\n", hora, minuto, segundo);
}

int main(int argc, char const *argv[]) {
	int hora, minuto, segundo;
	scanf("%d %d %d", &hora, &minuto, &segundo);

	print_horario(hora + 1, minuto, segundo);
	print_horario(hora + 2, minuto + 10, segundo + 30);
	print_horario(hora + 4, minuto + 40, segundo + 50);
	print_horario(hora + 12, minuto + 5, segundo + 5);
	return 0;
}