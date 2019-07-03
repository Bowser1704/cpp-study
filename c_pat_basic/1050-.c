#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}

int main()
{
	int N,array[10000],m,n;
	scanf("%d",&N);
	for (int i=0;i<N;i++)
		scanf("%d",array+i);

	qsort(array,N,sizeof(int),cmp);

//取出m，n的算法很微妙。只要m最小就可以(m>n为前提)
	for(m=1;!(m*m>=N&&N%m==0);m++) ;

	n=N/m;

	int put[m][n],m1=m,n1=n,i=0,j=-1,k=-1;
	while(m1>0&&n1>0){
		while(j<n1)
			put[i][++j]=array[++k];
		while(i<m1)
			put[++i][j]=array[++k];
		while(j>=0)
			put[i][--j]=array[++k];
		while(i>=0)
			put[--i][j]=array[++k];
	}

	for(int x=0;x<m;x++){
		for(int y=0;y<n;y++)
			printf("%d%c",put[x][y],y==n-1?'\n':' ');
	}


	return 0;
}
