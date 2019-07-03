#include <stdio.h>

int main()
{
	int n,m,x;
	int a[1000];
	scanf("%d%d",&n,&m);
	x=n-m;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		a[i+n]=a[i];
	}
	for(int i=0;i<n;i++){
		printf("%d%c",a[i+x],i==n-1?'\n':' ');
	}
	return 0;
}
