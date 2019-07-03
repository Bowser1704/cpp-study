#include <stdio.h>
int main()
{
	int n,arr[1001]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b,c;
		scanf("%d-%d %d",&a,&b,&c);
		arr[a]+=c;
	}
	int max=1;
	for(int i=2;i<1001;i++){
		if(arr[i]>arr[max])
			max=i;
	}
	printf("%d %d\n",max,arr[max]);
	return 0;
}
