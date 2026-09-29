#include <stdio.h>

int recursive13(int n)
{
    if (n == 1)
        return 1;
    else 
        return n + recursive13(n-1);
}

float recursive14(float n)
{
    if (n == 1)
        return 1;
    else 
        return 1/n + recursive14(n-1);
}

int main(void)
{
    int n;
    
    printf("n을 입력하세요:");
    scanf("%d", &n);
    printf("1 + ... %d는 %d\n", n, recursive13(n));
    printf("1/1 + ... 1/%d는 %.2f\n", n, recursive14(n));
}