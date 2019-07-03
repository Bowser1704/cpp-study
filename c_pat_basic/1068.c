#include <stdio.h>
#include <math.h>
int f(int a,int b,int A[a][b],int i,int j,int t)
{
	int sum=0;
	for(int k=i-1;k<=i+1;k++)
	{
		for(int l=j-1;l<=j+1;l++)
		{
			if(k==i&&l==j)
				continue;
			else if(abs(A[i][j]-A[k][l])<=t)
				return 0;
			else
				sum++;
		}
	}
	if(sum==8)
		return 1;
	else
		return 0;	
}
int main()
{
	int m,n,t;
	scanf("%d%d%d",&m,&n,&t);
	int A[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	int sum=0,a,b,c=1;
	for(int i=1;i<n-1;i++)
	{
		for(int j=1;j<m-1;j++)
		{
			if(f(n,m,A,i,j,t)==1)
			{
				c=0;
				//printf("%d %d\n",i,j);
				for(int k=0;k<n;k++)
				{
					for(int l=0;l<m;l++)
					{	
						if(k==i&&l==j)
							continue;
						else if(A[k][l]==A[i][j]){
							c=1;
						//	printf("%d %d\n",k,l);
						}
					}
				}
			if(c==0)
			{
			a=i,b=j;
			sum++;
			//printf("%d %d %d\n",sum,i,j);
			}	
			//	printf("%d %d %d\n",sum,i,j);
			}
		}
	}
	if(sum>1)
		puts("Not Unique");
	else if(sum==0)
		puts("Not Exist");
	else
		printf("(%d, %d): %d\n",b+1,a+1,A[a][b]);
	return 0;
}
