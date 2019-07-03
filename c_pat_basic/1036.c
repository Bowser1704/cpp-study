#include <stdio.h>
int main()
{
	int n;
	char c;
	scanf("%d %c",&n,&c);
	for(int i=0;i<(n+1)/2;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0||i==(n-1)/2||j==0||j==n-1)
				putchar(c);
			else
				printf(" ");
		}
		printf("\n");
	}
	return 0;
}
