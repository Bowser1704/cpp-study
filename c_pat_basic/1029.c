#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
	char s1[81],s2[81];
	int A[81]={0},B[256]={0},j=0;
	scanf("%s",s1);
	scanf("%s",s2);
	int len=strlen(s1),l=0;
//	printf("%d",len);

	for(int i=0;i<len;i++)  //注意_代表空格
	{
		if(s1[i]!=s2[j]){
            		if(B[toupper(s1[i])-'0']==0){
			    	A[l]=i;
                		B[toupper(s1[i])-'0']=1;
				l++;
            		}
        	}
		else
			j++;
	}

	for(int i=0;i<l;i++)
		printf("%c",toupper(s1[A[i]]));
	puts("");

	return 0;
}
