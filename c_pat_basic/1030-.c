#include <stdio.h>
#include <stdlib.h>
int comfunc (const void *a, const void *b){
	return (*(int*)a - *(int*)b);
}
//qsort 比较的函数(不理解)
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	int A[n];
	for(int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	qsort(A,n,sizeof(int),comfunc);
	
/*	for(int i=0;i<n;i++){
		printf("%d",A[i]);
	}
	for(;sum>1;sum--){
		int x=n-sum;
		if(A[sum]<=A[x]*p)
			break;

	for(int x=n-1;x>0;x--){
		if(A[x]<=A[0]*p)
			a=x+1;
	}
	for(int i=0;i<n-1;i++){
		if(A[n-1]<=A[i]*p)
			b=n-i;
	}
	sum=a>b?a:b;
	printf("%d",sum);
*/
	int sum,a,b;
	for(int i=n;i>1;i-=2){
		a=n-i;b=i-1;

		if(A[b]<=A[a]*p){
			sum=i;
			break;
		}
		else if(A[b-1]<=A[a]*p||A[b]<=A[a+1]*p){
			sum=i-1;
			break;
		}
	}
	printf("%d",sum);
	return 0;
}
