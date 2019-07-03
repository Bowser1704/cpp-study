#include <stdio.h>
int main()
{
	int n,l,h;
	scanf("%d%d%d",&n,&l,&h);
	int A[n][3],sum[n],a[100000]={0},b[100000]={0},c[100000]={0},d[100000]={0},re[n];
	for (int i=0;i<n;i++){
		scanf("%d",&A[i][0]);
		scanf("%d",&A[i][1]);
		scanf("%d",&A[i][2]);
		sum[i]=A[i][1]+A[i][2]
		if(A[i][1]>=l&&A[i][2]>=l){
			if(A[i][1]>=h&&A[i][2]>=h)
				a[i]=1;
			else if(A[i][1]>=h&&A[i][2]>=l)
				b[i]=1;	
			else if(A[i][1]<h&&A[i][2]<h&&A[i][1]>A[i][2])
				c[i]=1;
			else (A[i][1]>=h&&A[i][2]>=h)
				d[i]=1;
		}
	}
	for()

	retunrn 0;
}
