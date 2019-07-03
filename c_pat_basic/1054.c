//The problem is how to scanf and printf
//sscanf && sprintf
#include <stdio.h>
#include <string.h>

int main()
{
    int n,x,count=0;
    double input,sum=0;
    char st_in[100],st_out[100];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        x=1;
        scanf("%s",st_in);
        sscanf(st_in,"%lf",&input);
        sprintf(st_out,"%.2f",input);
        if(input>1000.0||input<-1000.0){
            x=0;
        }
        else{
            for(int i=0;i<strlen(st_in);i++){
                if(st_in[i]!=st_out[i]){
                    x=0;
                    break;
                }
            }
        }
        if(!x)
            printf("ERROR: %s is not a legal number\n",st_in);
        else{
            count++;
            sum+=input;
        }
    }

    if(count>1){                           //distinguish number and numbers 
        printf("The average of %d numbers is %.2f",count,sum/count);  
    }
    else if(count==1){
        printf("The average of 1 number is %.2f",sum);
    }
    else 
        printf("The average of 0 numbers is Undefined");
    
    return 0;
} 