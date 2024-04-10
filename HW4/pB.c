#include <stdio.h>

int main() {
	double sum = 1.0,division = 1.0,fraction = 0, before, sum_of_before = 0;
	int n, j, factorial ;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		factorial = i;
		division /= factorial;
		j = factorial;
		for(factorial == j;j>1 && j==factorial;j--){
			before = division*factorial;
			sum_of_before += before;
		}
	}
	sum = sum + division + sum_of_before;
	printf("%.12f\n",sum);
	return 0;
}

































