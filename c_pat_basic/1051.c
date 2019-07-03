#include <stdio.h>
#include <math.h>
int main()
{
	double a,b,c,d,e;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	e=a,a=a*cos(b),b=e*sin(b);
	e=c,c=c*cos(d),d=e*sin(d);
	double A,B;
	A=a*c-b*d;
	B=a*d+b*c;
	if(A<0&&A>-0.05)
		A=0;
	if(B<0&&B>-0.05)
		B=0;

	if(B>=0)
		printf("%.2f+%.2fi",A,B);
	else
		printf("%.2f-%.2fi",A,0-B);//也可以用abs这个函数。
	return 0;
}
