# include <stdio.h>
int main()
{
long long a, b, N, part1, part2, part3, part4, part5, result;
scanf("%lld,%lld,%lld", &a, &b, &N);
part1 = b*(2 << a-1);
part2 = a|b;
part3 = N/(2 << b-1);
part4 = a^b;
part5 = a&b;
result = part1 + part2 - part3 * part4 - part5;
printf("%lld",result);
return 0;
}
























