#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int s1=0,s2=0;
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int e=a+c;
		if(b==e&&d!=e)
			s1++;
		else if(d==e&&b!=e)
			s2++;
		else
			continue;
	}
	printf("%d %d\n",s2,s1);
	return 0;
}
