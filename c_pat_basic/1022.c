#include <stdio.h>
int main()
{
	int a,b,d;
	scanf("%d%d%d",&a,&b,&d);
	int sum=a+b;
	int A[1000],x=0;
//	while(sum!=0){
	for(int i=0;sum!=0;i++){
		A[i]=sum%d;
		sum/=d;
		x++;
	}
	for(int i=x-1;i>=0;i--)
		printf("%d",A[i]);
	if(x==0)
		printf("0");	//没有这个会有一个节点过不去
	return 0;
}
