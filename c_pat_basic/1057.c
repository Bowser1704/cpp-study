#include <stdio.h>
#include <ctype.h>

int main()
{
    int sum=0,array[2]={0};
    char c;
    while((c=getchar())!='\n'){     //notice priority
        if(isalpha(c))
            sum+=tolower(c)-'a'+1;
    }
    while(sum!=0){
        array[sum%2]++;
        sum/=2;
    }
    printf("%d %d\n",array[0],array[1]);
    return 0;
}