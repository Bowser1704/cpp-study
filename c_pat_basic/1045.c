#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int A[n],B[n];
    for(int i=0;i<n;i++){
        scanf("%d",A+i);
    }
    int sum=0,j=0;
    if(A[0]<A[1]){
        B[j]=0;
        j++;
        sum++;
    }
    for(int i=1;i<n-1;i++){
        if(A[i]>A[i-1]&&A[i]<A[i+1]){
            B[j]=i;
            j++;
            sum++;
        }
    }
    if(A[n-1]>A[n-2]){
        B[j]=n-1;
        sum++;
        j++;
    }
    for(int i=0;i<j-1;i++){
        for(int l=0;l<j-1-i;l++){
            if(A[B[l]]>A[B[l+1]]){
                int temp=A[B[l]];
                A[B[l]]=A[B[l+1]];
                A[B[l+1]]=temp;
            }
        }
    }
    printf("%d\n",sum);
    for(int i=0;i<j;i++){
        printf("%d%c",A[B[i]],i==j-1?'\n':' ');
    }

    return 0;
}