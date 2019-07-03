#include <stdio.h>
#include <ctype.h>
int main()
{
	char c;
	int bad[128]={0};

	while((c=getchar()) != '\n')
		bad[toupper(c)]=1;	//会自动转化为ascii码代表的数

	while((c=getchar()) != '\n'){
		if(!bad[toupper(c)] && !(isupper(c)&& bad['+']))
		//逻辑运算符的运用
			putchar(c);
	}
	return 0;
}
