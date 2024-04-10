#include <stdio.h>
int main()
	{
	long long num1,num2,den1,den2,resultnum,z=0,resultden;
	        scanf("%lld/%lld+%lld/%lld",&num1,&den1,&num2,&den2);
		resultnum=num1*den2+num2*den1;
		resultden=den1*den2;
		if(resultnum==resultden){
			printf("%lld",resultnum/resultden);
		}
		else if(resultnum==0){
			printf("%lld",z);
		}
		else    {
			printf("%lld/%lld",resultnum,resultden);
		}
		return 0;
	}
