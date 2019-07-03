#include <stdio.h>
int main()
{
	int n,m,x;
	int a[200];
	scanf("%d%d",&n,&m);
	m%=n;	/* M could be larger than N ,the subject is bullshit*/
	x=n-m;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=0;i<n;i++){
		printf("%d%c",a[i+x],i==n-1?'\n':' ');
		//Do not use "" (it's wrong)
	}
	return 0;
}
