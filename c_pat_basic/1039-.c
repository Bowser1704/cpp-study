#include <stdio.h>
#include <string.h>
int sub(char *s1,char *s2)
{	
	for(int i=0;s1[i]!='\0';i++){
		int x=1;
		for(int j=0;s1[j]!='\0';j++){
			if(s2[i]==s1[j]){
				x=0;
				break;
}
int main()
{
	char s1[1000],s2[1000];
	scanf("%s\n%s",s1,s2);
	int sum=0;
	for(int i=0;s2[i]!='\0';i++){
		int x=1;
		for(int j=0;s1[j]!='\0';j++){
			if(s2[i]==s1[j]){
				x=0;
				break;
			}
		}
		if(x){
			printf("No ");
			break;
		}
		else
			sum++;
	}
	if(sum==strlen(s2))
		printf("Yes ");
		
	
	return 0;
}
