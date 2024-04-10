#include <stdio.h>

int main()
{
	int days,starting_day,i,j,k;
	printf("Enter number of days in month: \n");
	scanf("%d",&days);
	printf("Enter starting day of the week (1=Sun, 7=Sat): \n");
	scanf("%d",&starting_day);

	for(j = 1;j<starting_day;++j){
	
		printf("   ");
	
	}
	for(i = 1;i<= days ;i++){
		for(k=starting_day;((i+(k-1))%7) != 0 && i != days;){
			printf("%2d",i);
			printf(" ");
			break;
		}
		for(;i== days;){
			printf("%2d",i);
			break;
						        }
		for(k = starting_day;((i+(k-1))%7) == 0 && i != days;){
			printf("%2d\n",i);
			break;
		}
		
	}
	return 0;
}






























