#include <stdio.h>
int main()
{
	int n,sum1=0;
	scanf("%d",&n);
	int A[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char B[]={'1','0','X','9','8','7','6','5','4','3','2'};
	for(int i=0;i<n;i++)
	{
		char s[18];
		int sum=0;
		scanf("%s",s);
		for(int j=0;j<17;j++)
		{
			if(s[j]<'0'||s[j]>'9')
			{
				printf("%s\n",s);
				break;
			}
			else
			//	sum+=(int)(s[j])*A[j];
				sum+=(s[j]-'0')*A[j];
		}
		int z=sum%11;
		if(B[z]!=s[17])
	//		printf("%s\n",s);//puts(s);
			puts(s);
		else
			sum1++;
	}
	if(sum1==n)
		puts("All passed");
	return 0;
}
