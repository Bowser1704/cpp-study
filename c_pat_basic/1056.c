#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int A[n],sum=0;
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i !=j)
				sum+=A[i]*10+A[j];	
		}
	}
	printf("%d\n",sum);
	return 0;
}
