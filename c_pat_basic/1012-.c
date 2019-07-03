#include <stdio.h>
int main()
{
	int n,a1=0,a2=0,a3=0,a5=0,k=0;
	float a4=0,x=0;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		int j;
		scanf("%d",&j);
		if (j%5==0){
			if(j%2==0)
				a1+=j;
		}
		else if(j%5==1){
			if(k==0){
				a2+=j; 
				k=1;
			}
			else{
				a2-=j; 
				k=0;
			}
		}

		else if(j%5==2){
			a3++;
		}
		else if(j%5==3){
			a4+=j;
			x++;
		}
		else{
			if(j>a5)
				a5=j;
		}
	}

	if(a1==0){     
		printf("N ");}   
	else{
		printf("%d ", a1);}
    
	if(a2==0){ 	
		printf("N ");}   
	else {
		printf("%d ", a2);
	}
	if(a3 == 0){     
		printf("N ");}   
	else {
		printf("%d ", a3);}
    
	if(a4 == 0){     
		printf("N ");}   
	else {
		printf("%.1f ", a4/x);}
    
	if(a5 == 0){     
		printf("N");}    
	else {
		printf("%d\n", a5);}

	return 0;
}
