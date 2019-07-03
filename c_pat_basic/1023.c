#include <stdio.h>
int main()
{
	int A[10],j=0;
	for (int i=0;i<10;i++){
		scanf("%d",&A[i]);
	}	
	for(int i=1;i<10;i++){
		if(A[i]!=0){
			printf("%d",i);
			j=i;
			A[i]--;
		}
		if(j!=0)
			break;
	}
	for(int i=0;i<10;i++){
		while(A[i]!=0){
			printf("%d",i);
			A[i]--;
		}
	}
	return 0;
}
