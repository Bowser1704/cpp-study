#include <stdio.h>
#include <ctype.h>
int main()
{
	char s1[61],s2[61],s3[61],s4[61];
	scanf("%s",s1);
	scanf("%s",s2);
	scanf("%s",s3);
	scanf("%s",s4);
	int c,j;
	char a,b;
	char *weekdays[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};	
//	char weekdays[][3] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};	
	for(int i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
	//	if (s1[i]==s2[i]&&isupper(s1[i])&&isupper(s2[i])){
		if (s1[i]==s2[i]&&s1[i]>='A'&&s2[i]<='G'){
				a=s1[i];
				j=i;
				break;
			}
		}
	for(int i=j+1;s1[i]!='\0'&&s2[i]!='\0';i++){
		if (s1[i]==s2[i]&&s1[i]>='A'&&s2[i]<='N'){
				b=s1[i];
				break;
		}
		else if(s1[i]==s2[i]&&isdigit(s1[i])){
				b=s1[i];
				break;
		}
	}

	for(int i=0;s3[i]!='\0'&&s4[i]!='\0';i++){
		if(s3[i]==s4[i]&&isalpha(s3[i])&&isalpha(s4[i])){
			c=i;
			break;
		}
	}
	
	if(b>='A'&&b<='N')
		printf("%s %02d:%02d\n",weekdays[a-'A'],b-'A'+10,c);
	else
		printf("%s %02d:%02d\n",weekdays[a-'A'],b-'0',c);
					
	return 0;
}
