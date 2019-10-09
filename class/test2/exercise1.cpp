#include <iostream>
#include <math.h>
using namespace std;

float isHaveSolution(float a, float b, float c) {
    return b*b - (4*a*c);
}
void printSolution(float a, float b, float c) {
    float solution = isHaveSolution(a, b, c);
    if (solution == 0) {
        printf("x1=x2=%0.5f",-b / (2*a));
    }else if (solution > 0) {
        solution = sqrt(solution);
        printf("x1=%0.5f;x2=%0.5f", (-b+solution) / (2*a), (-b-solution) / (2*a));
    }else {
        float x =  -b / (2*a), y = sqrt(4*a*c - b*b) / (2*a) ;
        printf("x1=%0.5f+%0.5fi,x2=%0.5f-%0.5fi",x,y,x,y);
    }
}
int main()
{
    float a, b, c;
    scanf("%f%f%f",&a,&b,&c);
    printSolution(a,b,c);
    return 0;
}

