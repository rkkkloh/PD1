#include <stdio.h>
#include <stdlib.h>

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long sum = a+b;
	if ((a>0 && b>0) || (a>0 && b<0) || (a<0 && b>0)){
		if ( sum < a && sum < b){
			printf("Yes");
		}else {
			printf("No");
		}

	}
	if (a<0 && b<0){
		if (sum > a && sum > b){
			printf("Yes");
		}else {
			printf("No");
		}

	}
	return 0;

}

































