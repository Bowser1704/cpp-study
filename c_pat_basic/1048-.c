//有一个坑是致命的：B的长度小于A时要将B前端补零后再进行加密。
#include <stdio.h>
#include <string.h>
int main()
{
	char s1[100],s2[100];
	scanf("%s %s",s1,s2);
	int len1=strlen(s1),len2=strlen(s2);
	int j=0;
	if(len2>len1){
		for(int i=0;i<len2-len1;i++)
			printf("%d",s2[i]-'0');
		j=len2-len1;
	}
	for(int i=j;i<len2;i++){
		if(i%2){
		//j是奇数但事实上是偶数位
			int  c=s2[i]-s1[i-j];
			//减去一个‘0’，再加上一个‘0’
			if(c<0)
				c+=10;
			printf("%d",c);
		}
		else{
		//奇数位
			int c=s2[i]+s1[i-j]-'0'-'0';
			c%=13;
			if(c<10)
				printf("%d",c);
			else if(c==10)
				printf("J");
			else if(c==11)
				printf("Q");
			else if("c==12")
				printf("K");
		}
	}

	return 0;
}
