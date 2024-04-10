#include <stdio.h>
#include <stdlib.h>

typedef double (*F)(double, int);

double power(double x, int n) {
	double result = 1.0;
	if (n < 0) {
	x = 1 / x;
	n = -n;
	}
	for (int i = 0; i < n; i++) {
		result *= x;
	}
	return result;
}

double multiply(double x, int n) {
	return x * n;
}

double divide(double x, int n) {
	if (n == 0) {
	printf("Error: Division by zero.\n");
	return 0;
	}
	return x / n;
}

double powerpower(F func, double x, int n, int m) {
	double result = func(x, n);
	double Result = 1.0;
	if (m < 0) {
	result = 1 / result;
	m = -m;
	}
	for (int i = 0; i < m; i++) {
		Result *= result;
	}
	return Result;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
	printf("PLEASE INPUT: %s <x> <n> <m>\n", argv[0]);
	return 1;
	}

	double x = atof(argv[1]);
	int n = atoi(argv[2]);
	int m = atoi(argv[3]);

	F ptr;

	ptr = &power;
	printf("(x^n): %lf\n", ptr(x, n));

	ptr = &multiply;
	printf("(x*n): %lf\n", ptr(x, n));

	ptr = &divide;
	printf("(x/n): %lf\n", ptr(x, n));

	printf("(x^n)^m: %lf\n", powerpower(&power, x, n, m));
	printf("(x*n)^m: %lf\n", powerpower(&multiply, x, n, m));
	printf("(x/n)^m: %lf\n", powerpower(&divide, x, n, m));
	
	return 0;
}

