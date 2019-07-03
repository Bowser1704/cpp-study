#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
	char s1[100000],s2[100000];
	scanf("%s\n%s",s1,s2);
	int len1=strlen(s1),len2=strlen(s2),b=0;
	for(int i=0;i<len1;i++){
		if(s1[i]=='+')
			b=1;
	}
	for (int i=0;i<len2;i++){
		int a=1;
		for(int j=0;j<len1;j++){
			if(toupper(s2[i])==s1[j]||(b==1&&isupper(s2[i]))){
				a=0;
				break;
			}
			
		}
		if(a==1)
		//	printf("%c",s1[i]);
			putchar(s2[i]);
	}
	printf("\n");
	
	return 0;
}
