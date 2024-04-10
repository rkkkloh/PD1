#include <stdio.h>

int main()
{long long C, GL1, GL2, GL3, TNOPGF, TC;
	scanf("%lld", &C);
	scanf("%lld", &GL1);
	scanf("%lld", &GL2);
	scanf("%lld", &GL3);
	TNOPGF = GL1/3 + GL2/3 + GL3/3;
	TC = (GL1+GL2+GL3-TNOPGF)*C;
	printf("%lld", TC);








	    return 0;
}
