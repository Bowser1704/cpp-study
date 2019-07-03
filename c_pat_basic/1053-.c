#include <stdio.h>
int main()
{
	int N,D,can_non=0,non=0;
	double e;
	scanf("%d %lf %d",&N,&e,&D);
	
	for(int i=0;i<N;i++){
		int x,low=0;
		scanf("%d",&x);
		for(int j=0;j<x;j++){
			double a;
			scanf("%lf",&a);
			if(a<e)
				low++;
		}
		if(low>D&&low>x/2)
		//problem is low>D
		//x>D is right
		//see what they mean
			non++;
		else if(low>x/2)
		//printf("%d\n",9/2); --->	4
			can_non++;
	}
	//printf("%d%%\n",90); --->	90%	
	printf("%.1f%%",can_non*100.0/N);
	printf(" %.1f%%\n",non*100.0/N);

	return 0;
}	
