#include <stdio.h>
int main()
{
	long long int a,s;
	int b,y;
	scanf("%lld%d",&a,&b);
	s=a/b;
	y=a%b;
	printf("%lld %d\n",s,y);
	return 0;
}
