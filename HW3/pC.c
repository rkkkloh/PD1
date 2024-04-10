#include <stdio.h>

int main()
{
	int a, b, c;
	scanf("%d-%d-%d", &a, &b, &c);
	if (a ==b && b==c){

	printf("400");

	}else if ((a == c && a < b) || (a + b < c && a >b)){

	printf("150");

	}else if (a == c){

	printf("100");

	}else if (a < b && a + b > c){

	printf("50");

	}else if (a < b && (a + b) < c){

	printf("200");

	}else {

	printf("0");

	}
return 0;
}



































