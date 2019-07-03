#include <stdio.h>

/*
void printanswer(float a,int n)
{
    if(a==0)
        printf("N%c",n==5?'\n':' ');
    else
        printf("%d%c",a,n==5?'\n':' ');
}
*/

int main()
{
    int N,n,a2counter=0,a4counter=0;
    scanf("%d",&N);
    int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0;
    for (int i=0;i<N;i++){
        scanf("%d",&n);
        switch(n%5){
            case 0:a1+= n%2? 0:n;   break;
            case 1:a2counter= a2counter==1?-1:1; a2+= a2counter*n;  break;
            case 2:a3++;    break;
            case 3:a4+=n; a4counter++;  break;
            case 4:a5=n>a5? n:a5;   break;
        }
    }
    if(a1 == 0)     printf("N ");   else printf("%d ", a1);
    if(a2counter == 0) printf("N ");   else printf("%d ", a2);
    if(a3 == 0)     printf("N ");   else printf("%d ", a3);
    if(a4 == 0)     printf("N ");   else printf("%.1f ",a4 * 1.0 / a4counter);
    if(a5 == 0)     printf("N");    else printf("%d", a5);
    return 0;
}
