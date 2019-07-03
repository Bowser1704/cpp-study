//aPbTc正确，aPbATca也正确。翻译一下，就是P和T中间每增加一个A，需要将P之前的内容复制到字符串末尾，得到的新字符串就也是正确的。
//T之后A的数量 = P之前A的数量 × P&T中间A的数量。

#include <stdio.h>

int main()
{
    char c;
    int num;
    scanf("%d", &num);
    while(getchar() != '\n');  /* read the rest of the line, 
                                  make sure to start from a new line later */
    for(int i = 0; i < num; i++)
    {
        /* pos: indicate the position of current index for count[]     */
        /* count[3]: number of As; before P, between P & T and after T */
        int pos = 0, count[3] = {0, 0, 0};
        while((c = getchar()) != '\n')
        {
            if(c == 'A')                  count[pos]++; /* count 'A's     */
            else if(c == 'P' && pos == 0) pos = 1;      /* one P before T */
            else if(c == 'T' && pos == 1) pos = 2;      /* one T after P  */
            else                          break;        /* 'wrong' string */
        }
        
        if(c == '\n'                        /* 1. no other characters at end */
        && pos == 2                         /* 2. appearance of 'P' and 'T'  */
        && count[1]                         /* 3. existance of 'A'           */
        && count[2] == count[1] * count[0]) /* 4. relation between numbers   */   
            puts("YES");
        else
            puts("NO");
        
        /* read the rest of the line */
        if(c != '\n')   
            while(getchar() != '\n'); 
    }
    
    return 0;
}
