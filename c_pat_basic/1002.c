#include <stdio.h>
int main()
{
	char s[100000];
	scanf("%s",&s);
	int sum=0;
	char *A[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};  //字符串的运用，字符串数组的定义。
	for(int i=0;s[i]!='\0';i++)
	{
		sum+=(s[i]-'0');
	}
	//while(sum)
	if(sum/100)
		printf("%s ",A[sum/100]);
	if(sum/10)
		printf("%s ",A[sum/10%10]);//先除10，把个位数去掉，再对10取余就是十位数。
	printf("%s",A[sum%10]);
	return 0;
}
