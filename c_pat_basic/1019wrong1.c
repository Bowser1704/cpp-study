#include <stdio.h>
#include <stdlib.h>
int sort1(int n)
{
	char s[4];
	sprintf(s,"%d",n);
	for(int i=0;i<3;i++){
		for(int j=i+1;j<=4;j++){
			if(s[i]<s[j]){
				char temp=s[j];
				s[j]=s[i];
				s[i]=temp;
			}
		}
	}
	return atoi(s);
		
}
int sort2(int n)	
{
	char s[4],temp[4];
	sprintf(s,"%d",n);
	temp[3]=s[0];
	temp[2]=s[1];
	temp[1]=s[2];
	temp[0]=s[3];

	return atoi(temp);
}	
int main()
{
	int n,re=1;
	scanf("%d",&n);
//	printf("%d%d",sort1(n),sort2(sort1(n)));
	while(re!=0&&re!=6174){
		re=sort1(n)-sort2(sort1(n));
		printf("%04d - %04d = %04d\n",sort1(n),sort2(sort1(n)),re);
		n=re;
	}

	return 0;
}
