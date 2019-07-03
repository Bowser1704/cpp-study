#include <stdio.h>
int main()
{
	int n,A[100000]={0},B[10000]={0},j=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		A[a]+=b;
		B[j]=a;
		j++;
	}
	int temp=0,max;
	for(int i=0;i<j;i++){
		if(A[B[i]]>temp){
			temp=A[B[i]];
			max=B[i];
		}
	}
	printf("%d %d\n",max,temp);
	return 0;
}
