#include <stdio.h>
int main()
{
	int n,A[101]={0};
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d ",&a);
		A[a]++;
	}
//	int x;
//	scanf("%d",&x);
//	A[x]++;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		printf("%d%c",A[a],i==n-1?'\n':' ');
	}
	return 0;
}
