#include <stdio.h>
int main()
{
	int n;
	float D,re;
	scanf("%d %f",&n,&D);	//整形与浮点在一起要用空格
//	printf("%d",n);
	float kc[n],pr[n];
	for(int i=0;i<n;i++){
		scanf("%f",kc+i);
	//	scanf("%f",&kc[i]);
	//	printf("%d %d",n,i);
	}
	for(int i=0;i<n;i++){
		scanf("%f",pr+i);
	//	scanf("%f",&pr[i]);
	//	printf("%d %d",n,i);
	}
	while(D!=0){
		int max=0;
		for(int i=1;i<n;i++){
			if((pr[i]/kc[i])>(pr[max]/kc[max]))
				max=i;
		}
		if(kc[max]<D){
			re+=pr[max];
			D-=kc[max];
			pr[max]=0;
		}
		else{
			re+=(pr[max]/kc[max])*D;
			D=0;
		}
	}
	printf("%.2f\n",re);
	return 0;
}
