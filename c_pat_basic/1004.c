#include <stdio.h>
int main()
{
	int n,max=0,min=100,x,a,b;
	scanf("%d",&n);
	char name[n][10];
	char id[n][10];
	for(int i=0;i<n;i++){
		scanf("%s %s %d",name[i],id[i],&x);
		if(x>max){
			max=x;
			a=i;
		}
		if(x<=min){
			min=x;
			b=i;
		}
	}
//	printf("%d %d %s",a,b,id[b]);
	printf("%s %s\n",name[a],id[a]);
	printf("%s %s\n",name[b],id[b]);
	return 0;
}
