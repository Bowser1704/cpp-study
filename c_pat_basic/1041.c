#include <stdio.h>
struct sample{
	char s[14];
	int a;
	int b;
};
int main()
{
	int n;
	scanf("%d",&n);
	struct sample in[n];
	for(int i=0;i<n;i++){
		scanf("%s %d %d",in[i].s,&in[i].a,&in[i].b);
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int x;
		scanf("%d",&x);
		for(int j=0;j<n;j++){
			if(x==in[j].a)
				printf("%s %d\n",in[j].s,in[j].b);
		}
	}

	return 0;
}
