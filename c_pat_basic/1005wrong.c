#include <stdio.h>
int find(int n,int A[])
{
	int j=0;
	for (int i=0;i<n;i++)
	{
		if(A[i]=n)
			j++;
	}
	if(j==0)
		return 0;
	else
		return 1;
}
int main()
{
	int n;
	scanf("%d",&n);
	int A[n];
	int re[n],j=0;
	for (int i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for (int i=0;i<n;i++){
		int x=1;
		while(A[i]!=1){
			if(n%2==0){
				n=n/2;
				if (find(n,A))
					continue;
				else{
					break;
					x=0;
				}
			}
			else{
				n=(3*n+1)/2;
				if (find(n,A))
					continue;
				else{
					break;
					x=0;
				}
			}
		}
		if(x==1){
			re[j]=A[i];
			j++;
		}
	}
	for(int i=0;i<j;i++)
	{
		for(int l=i+1;l<=j;l++)
		{
			if(re[l]<re[i]){
				int temp=re[l];
				re[l]=re[i];
				re[i]=temp;				
		}
		printf("%d ",re[i]);
		}
	}
	printf("%d\n",re[j]);
	return 0;
}
