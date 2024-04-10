#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

int Homework6_1(void)
{
	int i ,j,d;
	//scanf("%d",&j);
	srand((unsigned)time(NULL));
	j = rand() % (200000 - 5000 + 1) + 5000;
	printf("%d\n",j);
	int num[j];

	for(int i=0;i<j;i++){
		//scanf("%d",&num[i]);
		num[i] = rand() % (200000 - 5000 + 1) + 5000;
		if(j-i == 1){
		printf("%d",num[i]);
		}else{
		printf("%d ",num[i]);
		}
	}
	printf("\n");
	for(int i=(j-1);i>=0;i--){
		if(i!=0){
		printf("%d ",num[i]);
		}
		if(i==0){
		printf("%d",num[i]);
		}
	}
return 0;
}

void Homework6_2(void)
{
	long N, digit, digit2, sum = 0, Asum = 0;
	int I;
	//scanf("%ld",&N);
	srand((unsigned)time(NULL));
	N = rand() % 195001 + 5000;
	printf("%ld\n",N);
	long missing_num[N];
	digit = N;
	digit2 = N;
	I = rand() % N-1;
	for(;I>0;--I){
		int temp,x,y;
		x = rand()%N;
		y = rand()%N;
		temp = missing_num[x];
		missing_num[x] = missing_num[y];
		missing_num[y] = temp;
	}
	for (long i = 0; i < N-1;i++){
		missing_num[i] = i + 1;
		sum += missing_num[i];
		printf("%ld",missing_num[i]);
		if(i != N-2){
		printf(" ");
		}
	}
	sum += N;
	printf("\n");
	for(long i = 0;i < digit2-1;i++){
		Asum+=missing_num[i];
	}
	printf("%ld",sum-Asum);

}
long a[100001];
long pre[100001];
long n;
void init(void){
	a[0] = 0;
	pre[0] = 0;
	//scanf("%ld",&n);
	srand((unsigned)time(NULL));
	n = rand() % (100000 - 50000 + 1) + 50000;
	printf("%ld\n",n);
	for(int i = 0;i<n;i++){
		a[i] = rand() % (100000 - 50000 + 1) + 50000;
		printf("%ld",a[i]);
		if (i != n-1){
		printf(" ");
		}
	}
	printf("\n");
	for(int i = 1; i <= n; i++){
		pre[i] = pre[i - 1] + a[i-1];
		
	}
}
void Homework6_3(void)
{  long tmp,q,i=0;
	init();
	here:
	q = rand() % (100000 - 50000 + 1) + 50000;
	if (q<n){
	printf("%ld\n",q);
	long L[n],R[n];
	L[0]=0;
	R[0]=0;
	for(int i=0;i<q;i++){
	L[i] = rand() % n + 1 ;
	R[i] = rand() % n + 1;
	if(L[i]>R[i]){
		tmp=L[i];
		L[i]=R[i];
		R[i]=tmp;
	}
	printf("%ld %ld\n",L[i],R[i]);
		/*if(i!=q-1){
		printf("\n");
		}*/
	}
	
	for(int i = 0;i < q;i++){
	printf("%ld",pre[R[i]]-pre[L[i]-1]);
	if(i!=q-1){
	printf("\n");
	}
	}
	}else goto here;
}

void Homework6_4(void)
{
	srand(time(NULL));
	int n, m, r1,c1,r2,c2,s[5][4];
	n = rand() % (1000 - 500 + 1) + 500;
	m = rand() % (1000 - 500 + 1) + 500;
	printf("%d %d\n", n, m);
	int A[n][m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
		A[i][j] = rand() % 1000 + 1;
		if(m-j != 1){
		printf("%d ",A[i][j]);
		}else printf("%d\n",A[i][j]);
			/*if(n-i == 1){
			printf("%d",A[i][j]);
			}else{
			printf("%d\n",A[i][j]);
			}*/
		
		}	
	}
	for(int i = 0;i<5;i++){
		r1 = rand() % n + 1;
		c1 = rand() % m + 1;
		r2 = rand() % n + 1;
		c2 = rand() % m + 1;
		printf("%d %d %d %d\n", r1, c1, r2, c2);
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


















