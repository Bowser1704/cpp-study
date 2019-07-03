#include <stdio.h>
#include <math.h>
void output(int a,int b,int c,int d,int e,int f,char x)
{
	int e,e1,f,f1;	
	if(a>=b){
		e=a/b;
		e1=a%b;
	}
	if(abs(c)>=d){
		f=c/d;
		e1=abs(c)%d;
	}

}
int main()
{
	int a,b,c,d,e,e1,f,f1;
	scanf("%d/%d %d/%d",&a,&b,&c,&d);
	output(a,b,c,d,a*d+b*c,b*d,'+');
	output(a,b,c,d,a*d-b*c,b*d,'-');
	output(a,b,c,d,a*c,b*d,'*');
	output(a,b,c,d,a*d,b*c,'/');

	return 0;
}
