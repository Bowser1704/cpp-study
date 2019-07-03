#include <stdio.h>
int main()
{
	char s[4];
	scanf("%s",s);
//	printf("%s",s);
	if(s[0]==s[1]==s[2]==s[3]){
		printf("%s - %s = 0000",s,s);
	}
	return 0;
}
