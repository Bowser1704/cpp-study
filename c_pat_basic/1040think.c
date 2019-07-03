#include <stdio.h>

#define LIM 1000000007

int main()
{
    int P = 0, PA = 0, PAT = 0;
    char c;
    
    while((c = getchar()) != '\n')
    {
        if(c == 'P')   P++,printf("P= %d\n",P);
	//把最前面的所有P给记录下来
        if(c == 'A')   PA = (PA + P) % LIM,printf("PA= %d\n",PA);
	//遇到A之后就‘加’上P，实际上是×(多次加)
        if(c == 'T')   PAT = (PAT + PA) % LIM,printf("PAT= %d\n",PAT);
	//最后统计T，×前面的PA。OVER
    }
    printf("%d", PAT);
    
    return 0;
}
