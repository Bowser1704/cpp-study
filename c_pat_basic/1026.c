#include <stdio.h>
int main()
{
	int A[3];
	int j,k,n;
	scanf("%d%d",&j,&k);
	n=(k-j)/100;
	double m=k-j; //利用类型强制转换
	m=m/100;	//整形除以100得到整数就算浮点也是58.000000000
	int l=(int)(m+0.5); //四舍五入的方法
	A[2]=(l%60);
	A[1]=(n/60)%60;
	A[0]=((n/60)/60);
	printf("%02d:%02d:%02d",A[0],A[1],A[2]);
	return 0;
}
