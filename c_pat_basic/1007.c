#include <stdio.h>
#include <math.h>
int prime(int n)
{
	if (n%2 == 0)
        	return n==2;
    	else if (n%3 == 0)
        	return n==3;
    	else if (n%5 == 0)
        	return n==5;         
	//只考虑奇数作为可能因子
	for(int i=7;i<sqrt(n)+1;i+=2){
        	if (n%i == 0)
            		return 0;
	}
    	return 1;
}

int main()
{
	int n,j=0,sum=0,b;
	scanf("%d",&n);
	int array[10000]={0};
	
	for(int i=1;i<n+1;i++){
		if (prime(i))
			array[++j]=i;
	}
	for(int i=1;i<=j;i++){
		b=array[i+1]-array[i];
		if(b==2)
			sum++;
	}
	printf("%d\n",sum);	
	return 0;	
}
