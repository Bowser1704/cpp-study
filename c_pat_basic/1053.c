#include <stdio.h>
int main()
{
	int N,D,can_non=0,non=0,x,low;
	double e,a;
	scanf("%d %lf %d",&N,&e,&D);
	
	for(int i=0;i<N;i++){
		low=0;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			scanf("%lf",&a);
			if(a<e)
				low++;
		}
		if(x>D&&low>x/2)
			non++;
		else if(low>x/2)
		//printf("%d\n",9/2); --->	4
			can_non++;
	}
	//printf("%d%%\n",90); --->	90%	
	printf("%.1f%%",100.0*can_non/N);
	printf(" %.1f%%\n",100.0*non/N);

	return 0;
}	
