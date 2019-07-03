/*
问题在于怎么去比较答案的对错
有一种神奇的想法就是利用一个数二进制位移,并且按位或运算,这样能够用一个数字来储存答案是否正确
巧妙利用位运算
*/
#include <stdio.h>

typedef struct prob
{
    /* data */
    int score;
    int answer; //正确回答
    int wrong;  //错误人数
}Prob;

int readanswer();
int main(){
    int N, M, max=0, useless=0; //正确选项个数useless没有用的数据
    Prob probs[100];
    scanf("%d %d",&N, &M);

    /*读取(M)每个问题到struct里面 */
    for(int i=0; i < M; i++){
        scanf("%d %d",&probs[i].score, &useless);
        probs[i].wrong = 0;
        probs[i].answer = readanswer();
    }

    /*读取(N)每个同学的回答 */
    for (int i=0; i<N; i++){
        int score = 0;
        /*读取同学的(M)每个回答 */
        for (int j=0; j<M; j++){
            while(getchar() != '(');    //如果没有(则一直循环
            if (readanswer() == probs[j].answer)
                score += probs[j].score;
            else if (max < ++probs[j].wrong)
                max = probs[j].wrong;
            while(getchar() != ')');    //如果没有)也一直循环
        }
        printf("%d\n",score);
    }
    if(max == 0) printf("Too simple");
    else
    {
        printf("%d",max);
        for(int i=0; i<M; i++){
            if(probs[i].wrong == max)
                printf(" %d",i+1);
        }
    }
    return 0;
}

int readanswer(){
    char c;
    int count, answer = 0;
    scanf("%d",&count);
    for (int i=0; i < count; i++){
        while((c=getchar())==' ');
        answer |= 1 << (c - 'a');   //按位或运算,储存答案正确与否
    }
    return answer;
}