#include <stdio.h>
#include <math.h>

int prime(int n)
{	
	int x=sqrt(n);	
	if(n==2||n==3||n==5||n==7)
		return 1;
//	else if(n!=2 && n!=3 && n!=5 && n!=7){
	else{
		if(n%2==0||n%3==0||n%5==0||n%7==0)
			return 0;
		else{
		//	x=sqrt(n)
			for(int i=2;i<=x;i++){
				if(n%i==0)
					return 0;
			}
			return 1;
		}
	}
}
	
int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	int A[n],j=0,l=1;
//	static int a=2;
	for(int i=0;i<n;i++){
		static int a=2;
		for (a;a>0;a++){
			if (prime(a)){
			//	printf("%d",a);
				A[j]=a;
				a++;
				j++;
				break;
			}
		}
	}
	for (int i=m-1;i<n;i++){
		printf("%d%c",A[i],(l%10==0 || i==n-1)?'\n':' ');
		l++;
	}
	return 0;
}
