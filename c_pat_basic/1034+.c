#include <stdio.h>
//该题说不超过整形的数字，即表明有长整形

long calcgcd(long a, long b)	//省略int long == long int
{
	long r;
	while((r=a%b))	//r=0,不执行；r>0,执行。
	{
		a=b;
		b=r;
	}
	return b;
	// 求a与b的最大公因数
}

//打印分数
void printfrac(long n, long d)
{
	if(d==0) { 
		printf("Inf");
		return;
	}

	int inegative =1;
	if(n < 0) { 
		n = -n; 
		inegative *= -1; 
	}
     	if(d < 0) { 
		d = -d; 
		inegative *= -1; 
	}

	//约分
	long gcd =calcgcd(n,d);
	n/=gcd;
	d/=gcd;

	//print
	if(inegative == -1)  printf("(-");
     	if(n / d && n % d)   printf("%ld %ld/%ld", n / d, n % d, d); /* n>d,n%d!=0*/
     	else if(n % d)       printf("%ld/%ld", n % d, d);            /* n<d*/
     	else                 printf("%ld", n / d);                   /* n是d的倍数，即d==1*/
     	if(inegative == -1)  printf(")");
 }

//正常输入，计算，输出。
int main()
{
	long a1, b1, a2, b2;
     	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

	char op[4] = {'+', '-', '*', '/'};
     	for(int i = 0; i < 4; i++)
     	{
         printfrac(a1, b1);        printf(" %c ", op[i]);
         printfrac(a2, b2);        printf(" = ");
         
	 //原则上不用switch，用if else if。哈哈哈
	 switch(op[i])
         {
             case '+': printfrac(a1 * b2 + a2 * b1, b1 * b2); break;
             case '-': printfrac(a1 * b2 - a2 * b1, b1 * b2); break;
             case '*': printfrac(a1 * a2,           b1 * b2); break;
             case '/': printfrac(a1 * b2,           b1 * a2); break;
         }

         printf("\n");
    	 }
	return 0;
}


