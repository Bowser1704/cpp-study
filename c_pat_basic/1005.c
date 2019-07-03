#include <stdio.h>
int main()
{
	int n,A[10000]={0},x;
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",&x);
		A[x]=1;
	}
	for (int i=0;i<101;i++){
		if (A[i]==1){
		for(int y=i;y>1;){
			if(y%2){
				y=(3*y+1)/2;
			}
			else{
				y=y/2;
			}

			if(A[y]==1){
				A[y]=0;
				n--;
				if(y<i)
					break;
			}
		}
	}
	}
	for (int i=100;i>1;i--){
		if(A[i]){
			printf("%d%c",i,n==1?'\n':' ');
			n--;
		}
	}
	return 0;
}
