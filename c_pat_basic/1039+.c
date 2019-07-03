#include <stdio.h>
int main()
{
	char c;
	int record[128]={0};//先定义一个数组存放各个字母的数量
	while((c=getchar())!='\n')
		record[(int)c]++;

	while((c=getchar())!='\n')
		record[(int)c]--;//需要的就减去，看少了什么多了什么。

	int more=0,less=0;
	for(int i=0;i<128;i++)
	{
		if(record[i]>0)
			more+=record[i];//看多了几个
		if(record[i]<0)
			less-=record[i];//看少了几个
	}
	if(less)
		printf("No %d",less);//如果少了，就是NO。
	else
		printf("Yes %d",more);
	return 0;
}
