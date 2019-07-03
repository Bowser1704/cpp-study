#include <stdio.h>
int main()
{
	int a,b,c,d,e,f;
	scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&d,&e,&f);
	long yf=a*29*17+b*29+c,sf=d*29*17+e*29+f;
	long sub=sf-yf;
	if(sub<0){
		putchar('-');
		sub=-sub;
	}
	int j,k,l;
	j=sub/(29*17);
	k=(sub%(29*17))/29;
	l=(sub%(29*17))%29;
	printf("%d.%d.%d\n",j,k,l);
	return 0;
}
