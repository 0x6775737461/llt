#include <stdio.h>
#include <stdlib.h>

double farenheit(double);

int main(int argc, char *argv[]){
	char *check = NULL;
	double n = 0;

	if(argc != 2)
		return 1;
	
	n = strtod(argv[1], &check);

	if(check)
		printf("[%10.2f ºC]\t[%10.2f ºF]\n", n, farenheit(n));
	else
		return 1;
	
	return 0;
}

double farenheit(double celsius) { return ((9.0/5.0) * celsius + 32); }
