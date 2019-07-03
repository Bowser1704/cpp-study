#include <stdio.h>
int main()
{
	int n,a=0,b=0,c=0;
	scanf("%d",&n);
	char A[]={'B','C','J'};
	int B[3]={0},C[3]={0};
	for(int i=0;i<n;i++)
	{
		char s1,s2;
		scanf(" %c %c",&s1,&s2); //前面一定要有一个空格。
		if((s1=='C'&&s2=='J')||(s1=='J'&&s2=='B')||(s1=='B'&&s2=='C'))
		{
			for(int j=0;j<3;j++)
			{
				if(s1==A[i])
					B[i]++;
			}
			a++;
		}
		else if(s1==s2)
			b++;
		else{
			for(int j=0;j<3;j++)
			{
				if(s2==A[i])
					C[i]++;
			}
			c++;	
		}
	}
	int max1=0,max2=0;
	for(int i=1;i<3;i++)
	{
		int temp=B[0];
		if(B[i]>B[0])
			max1=i;
	}
	for(int i=1;i<3;i++)
	{
		int temp=C[0];
		if(C[i]>C[0])
			max2=i;
	}
	printf("%d %d %d\n",a,b,c);
	printf("%d %d %d\n",c,b,a);
	printf("%c %c\n",A[max1],A[max2]);
	
	return 0;
}

