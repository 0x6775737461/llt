#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void usage(void);
static int param_checker(const char *);

double farenheit(double);
double celsius(double);

int main(int argc, char *argv[]){
	//select the function to convert, according to param
	double (*conv_pick[2])(double) = {farenheit, celsius};
	char *check = NULL;
	double converted, n;

	//TODO: if argc < 2 the programs broke
	int valid_param = param_checker(argv[1]);
	if(argc != 3 || !(valid_param >= 0)) {
		usage();
		return EXIT_FAILURE;
	}
		
	n = strtod(argv[2], &check);
	if(*check) {
		fprintf(stderr,
						"\r[ERROR] Invalid Value: %s!\n", argv[2]);
		return EXIT_FAILURE;
	}
	
	//this attribute should be used in future versions
	converted = conv_pick[valid_param](n);

	return 0;
}

void usage(void) {
	fprintf(stderr, "\rUsage:\n"
					"\r\t# Converting Celsius to Farenheit\n"
					"\r\t$ ./llt -cf [0-9]\n\n"
					"\r\t# Converting Farenheit to Celsius\n"
					"\r\t$ ./llt -fc [0-9]\n\n");
}

int param_checker(const char *param) {
	const char *valid_params[2] = {"-cf", "-fc"};

	//i == number of func converter
	for(int i = 1; i >= 0; i--) {
		if(strcmp(param, valid_params[i]) == 0)
			return i;
	}

	fprintf(stderr,
				"\r[ERROR] Invalid Parameter: %s!\n", param);

	return -1;
}

//
//Converters
//

double farenheit(double celsius) {
	double converted = (9.0 / 5 * celsius + 32);
	printf("[%10.2fºC]\t[%10.2fºF]\n", celsius, converted);

	return converted;
}

double celsius(double farenheit) {
	double converted = 5.0 / 9 * (farenheit - 32);
	printf("[%10.2fºF]\t[%10.2fºC]\n", farenheit, converted);

	return converted;
}
