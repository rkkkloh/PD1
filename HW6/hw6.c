#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int Homework6_1(void)
{
	int i ,j,d;
	scanf("%d",&j);
	int num[j];

	for(int i=0;i<j;i++){
		scanf("%d",&num[i]);
	}
	for(int i=(j-1);i>=0;i--){
		if(i!=0){
		printf("%d ",num[i]);
		}
		if(i==0){
		printf("%d",num[i]);
		}
	}
return 0;
					            /*(for(i=9;i>=0;i--){
						     *             printf("%d ",num[i]);
						     *                     }*/
					        /*int i,j,num[j];
						 *     scanf("%d",&j);
						 *         for(i=0;i<j;i++){
						 *                 scanf("%d",&num[j]);
						 *                         printf("%d",num[j]);
						 *                                 j++;
						 *                                     }*/
}

void Homework6_2(void)
{
	long N, digit, digit2, sum = 0, Asum = 0;
	scanf("%ld",&N);
	int missing_num[N];
	digit = N;
	digit2 = N;
	for (int i = 1;i<=N;i++){
		sum +=i;
	}
	for (int i = 0;i < N;i++){
		missing_num[i]=0;
	}
	for (int i = 0 ; i < digit-1 ; i++){ 
 		scanf("%d",&missing_num[i]);
	}
	for(int i = 0;i < digit2;i++){
		if(!missing_num[i]){
			for(int j = 0; j < digit2;j++){
				Asum += missing_num[j];
			}
			printf("%ld",sum-Asum);
			break;
		}
	}
}
long a[100001];
long pre[100001];
long n;
void init(void){
	a[0] = 0;
	pre[0] = 0;
	scanf("%ld",&n);
	for(int i = 0;i<n;i++){
		scanf("%ld",&a[i]);
	}
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i-1];
	}

}
long query(long r, long l){
	return pre[r] - pre[l - 1];
}
void Homework6_3(void)
{   long n,l,r,q,i=0;
	init();
	scanf("%ld",&q);
	long L[q],R[q];
	L[0]=0;
	R[0]=0;
	for(int i=0;i<q;i++){
	scanf("%ld%ld",&L[i],&R[i]);
	}
	for(int i = 0;i < q;i++){
	if((q-i) != 1)printf("%ld\n",query(R[i],L[i]));
	else{printf("%ld",query(R[i],L[i]));}
	}
}

void Homework6_4(void)
{
	int n, m, r1,c1,r2,c2;
	scanf("%d%d",&n,&m);
	int A[n][m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
		scanf("%d",&A[i][j]);
		}
	}
	for(int i = 0;i<5;i++){
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int temp = A[r2-1][c2-1];
		A[r2-1][c2-1] = A[r1-1][c1-1];
		A[r1-1][c1-1] = temp;
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			if(m-j!=1){
			printf("%d ",A[i][j]);
			}else{
				if(n-i == 1){
				printf("%d",A[i][j]);
				}else{
				printf("%d\n",A[i][j]);
				}
			}
		}
	}
}
int main()
{
	int opt;
	scanf("%d",&opt);

	if (opt == 1)
	{
		Homework6_1();
	}
	else if (opt == 2)
	{
		Homework6_2();
	}
	else if (opt == 3)
	{
   		Homework6_3();
	}
	else
	{
		Homework6_4();
	}
	return 0;
}


















