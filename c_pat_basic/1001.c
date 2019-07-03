#include <stdio.h>
int f(int n)
{
	int sum=0;
	while(n!=1){
		if(n%2==0){
			n=n/2;
			sum++;
		}
		else{
			n=3*n+1;
			n=n/2;
			sum++;
		}
	}
	return sum;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n));
}
