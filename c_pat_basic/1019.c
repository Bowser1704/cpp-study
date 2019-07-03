#include <stdio.h>
#include <stdlib.h>
int sort1(int n)
{
	char s[4];
	sprintf(s,"%d",n);
	for(int i=0;i<3;i++){
		for(int j=i+1;j<=4;j++){
			if((int)(s[i])<(int)(s[j])){
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
	return n/1000 + n%1000/100 * 10 + n%100/10 * 100 + n%10 * 1000;
}	
int main()
{
	int n,re=1;
	scanf("%d",&n);
//	printf("%d%d",sort1(n),sort2(sort1(n)));
	while(re!=0&&re!=6174){
		int x=sort1(n),y=sort2(x);
		re=x-y;
		printf("%04d - %04d = %04d\n",x,y,re);
		n=re;
	}

	return 0;
}
