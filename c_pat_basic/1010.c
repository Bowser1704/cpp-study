#include <stdio.h>
int main()
{
	int a,b,c=0;
	while(scanf("%d%d",&a,&b)!=EOF){
		if(b!=0){
			if(c!=0)
				putchar(' '); //不换行且第一个数据不输出空格
			printf("%d %d",a*b,b-1);
			c++;
		}
	}
	if (c==0)
		printf("0 0");
	return 0;
}
