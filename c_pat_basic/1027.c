#include <stdio.h>
#include <math.h>
void prc(int n,char c,int n1)
{
	int j=n1-n;
	int n2=2*n-1;
	for(;j;j--){
		putchar(' ');
	}
	for(int i=0;i<n2;i++){
		putchar(c);
	}
	putchar('\n');
}
int main()
{
	int x,n,re;
	char c;
	scanf("%d %c",&x,&c);
	n=(int)(sqrt((x+1)/2));
	re=x-(2*n*n-1);
	int n1=n;
	//前面输出空格 后面不要。
	for(;n1>0;n1--){
		prc(n1,c,n);
	}
	for(int i=2;i<=n;i++){
		prc(i,c,n);
	}

	printf("%d",re);		

	return 0;
}
