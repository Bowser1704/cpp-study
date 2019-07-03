#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *units[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", 
    "aug", "sep", "oct", "nov", "dec"};
char *tens[] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", 
    "syy", "lok", "mer", "jou"};

int Mars2Earth(char *s)
{
    if(s)
    {
        for(int i = 0; i < 13; i++)         /* units digits */
            if(strcmp(s, units[i]) == 0)
                return i;
        for(int i = 1; i < 13; i++)         /* tens digits */
            if(strcmp(s, tens[i - 1]) == 0)
                return i * 13;
    }
    return 0;
}

int main()
{
    int N, m;
    
    scanf("%d", &N);
    for(int i = 0; i < N+1; i++)
    {
    	char line[11];
        //scanf("%s",line);
		gets(line);
        if(isdigit(line[0]))                  /* Earth number */
        {
            int m=atoi(line);
            if(m / 13 && m % 13)
                printf("%s %s\n", tens[m / 13 - 1], units[m % 13]);
            if(m / 13 && m % 13 == 0)
                printf("%s\n", tens[m / 13 - 1]);
            if(m / 13 == 0)
                printf("%s\n", units[m % 13]);
        }
        if(isalpha(line[0]))                  /* Mars number */
        {
			char s[2]=" ";
            m = Mars2Earth(strtok(line, s));        /* higher digit */
            m += Mars2Earth(strtok(NULL, s));       /* loelo nov wer digit */
            printf("%d\n", m);
        }
    }
    
    return 0;
}