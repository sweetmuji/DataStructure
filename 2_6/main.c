#include <stdio.h>

int fibo(int n)
{
    if(n==0)
    {
        printf("0번 항에 도달.. 0을 더합니다.\n");
        return 0;
    }
    else if(n==1)
    {
        printf("1번 항에 도달.. 1을 더합니다.\n");
        return 1;
    }
    else
        return (fibo(n-1) + fibo(n-2));
}

int main(void)
{
    int n;
    printf("구하고 싶은 피보나치 수열의 번호를 입력하세요:");
    scanf("%d", &n);
    
    printf("%d\n", fibo(n));
    
    return 0;
}