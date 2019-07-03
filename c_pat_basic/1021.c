#include <stdio.h>
int main()
{
	char s[1001];
	scanf("%s",&s);	//定义一个字符串，输入一个字符实在是太牛逼。
	int A[10]={0};
	for(int i=0;s[i]!='\0';i++)
	{
		A[s[i]-'0']++;	//已经定义好了0，1，2，3.。。 再用s[i]-'0'等于去字符化 变为整i型。n妙！
	}
	for(int i=0;i<10;i++)
	{
		if(A[i]!=0)
			printf("%d:%d\n",i,A[i]);	//感受到自己的孤陋！！!
	}
	return 0;	
}
