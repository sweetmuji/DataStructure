#include <stdio.h>

int binomial_coefficient(int n, int k)
{
    if ((n == k) || (k == 0))
        return 1;
    else
        return binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k);
}

int main(void)
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    printf("%d\n", binomial_coefficient(a, b));
}