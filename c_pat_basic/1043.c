#include <stdio.h>
int main()
{
	int A[128]={0};
	char c;
	//学会字符串题目用这种方法
	while((c=getchar())!='\n'){
		//A 65 P 80 T 84 e 101 s 115 t 116
		A[(int)c]++;
	}
	//早知道写个函数。。。
	while(A[65]||A[80]||A[84]||A[101]||A[115]||A[116]){
		if(A[80]){
			printf("%c",80);
			A[80]--;
		}
		if(A[65]){
			printf("%c",65);
			A[65]--;
		}
		if(A[84]){
			printf("%c",84);
			A[84]--;
		}
		if(A[101]){
			printf("%c",101);
			A[101]--;
		}
		if(A[115]){
			printf("%c",115);
			A[115]--;
		}
		if(A[116]){
			printf("%c",116);
			A[116]--;
		}
	}
	return 0;
}
