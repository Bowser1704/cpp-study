#include  <stdio.h>
int main()
{
    int n;
    double sum=0,x;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
     //   double x;
        scanf("%lf",&x);
     //   sum+=(n-i)*(i+1)*x;
     //     x必须要放在最前面
     //     to avoid overflow
        sum+=x*(n-i)*(i+1);
    }
    printf("%.2lf",sum);

    return 0;
}