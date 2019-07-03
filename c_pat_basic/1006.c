#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n / 100;     i++)    putchar('B');
    for(int i = 0; i < n / 10 % 10; i++)    putchar('S');
    //The last print is worth thinking .
    for(int i = 0; i < n % 10;      i++)    putchar('1' + i);

    return 0;
}