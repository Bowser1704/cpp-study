#include <stdio.h>
#include <ctype.h>
int main()
{
	int output[26]={0};
	char c;
	while((c=getchar())!='\n')
	{
		if(isalpha(c))
		{
		//	c=tolower(c);
			output[tolower(c)-'a']++;
		}	
		//	printf("%d\n",output[i]);
		
	}
	int max=output[25],p;
	for(int i=24;i>=0;i--)
	{
		if(output[i]>=max)
		{
			max=output[i];
			p=i;
		}
	}
	printf("%c %d\n",p+'a',max);
	return 0;
}