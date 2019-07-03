#include <stdio.h>
#include <string.h>

int main()
{
	char s[10000];
	scanf("%s",s);
	char *s1,*s2;

	s1=strtok(s,'E');
	while(s1 != NULL){
		s2=strtok(NULL,s);
	}
	return 0;
}
