#include <stdio.h>
int main()
{
	char s[100000];
	int sum=0;
	scanf("%s",s);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='P'){
			for(int j=i;s[j]!='\0';j++){
				if(s[j]=='A'){
					for(int l=j;s[l]!='\0';l++){
						if(s[l]=='T')
							sum++;
					}
				}
			}
		}
	}
	printf("%d",sum%1000000007);
	return 0;
}
