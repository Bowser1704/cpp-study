#include <stdio.h>

int main()
{
	int ex;
	char s[10000], *p=s;
	scanf("%[^E]E%d",s,&ex);
	//正则表达式
	
	if(*p++ == '-') putchar('-');
	//为什么要++ *p不是指向了第一个字符的地址吗？
	//先输出*p后再++。注意i++ 与 ++i 的区别
	
	if(ex>=0){
		putchar(*p);
		//这里的putchar是什么意义呢？
		//输出第一个
		for(p +=2;ex;ex--)
			putchar(*p? *p++:'0');
		if(*p){
			putchar('.');
			while(*p) putchar(*p++);
		}

	}
	if(ex<0){
		printf("0.");
		for(ex++;ex;ex++)	//输出0
			putchar('0');
		//先ex++的原因是输出了0. 已经退了一位
		for(;*p;p++){			//这里的循环条件当*p为空字符的时候终止循环。
			if(*p != '.')
				putchar(*p);	//输出数
		}
	}	
	return 0;
}
