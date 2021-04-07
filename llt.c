#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(void);
static int param_checker(const char *);

double farenheit(double);

int main(int argc, char *argv[]){
	char *check = NULL;
	double n = 0;

	if((argc != 3) || !param_checker(argv[1])) {
		usage();
		return EXIT_FAILURE;
	}
		
	n = strtod(argv[2], &check);
	if(*check) {
		fprintf(stderr,
						"\b[ERROR] Invalid Value: %s!\n", argv[2]);
		return EXIT_FAILURE;
	}

	printf("[%10.2f ºC]\t[%10.2f ºF]\n", n, farenheit(n));
	
	return 0;
}

void usage(void) {
	fprintf(stderr,
					"\bUsage:\n"
					"\b\t#Converting Celsius to Farenheit\n"
					"\b\t$ ./llt -cf [0-9]\n");
}

int param_checker(const char *param) {
	//TODO: think of another way to check mult params..
	return !strcmp(param, "-cf");
}

//Converters
double farenheit(double celsius) { return (9 / 5 * celsius + 32); }
