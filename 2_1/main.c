#include <stdio.h>

int power_1(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else
    {
        return x * power_1(x, n-1);
    }
}

int power_2(int x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    else if(n%2 == 0)
    {
        return power_2(x*x, n/2);
    }
    else if(n%2 == 1)
    {
        return x * power_2(x*x, (n-1)/2);
    }
}

int main(void)
{
    printf("2^3은 %d\n", power_2(2, 9));
}