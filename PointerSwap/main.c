#include <stdio.h>

void pointerSwap(int* px, int* py) // int* 즉, 주소를 매개변수로 입력 받는다!
{
    int temp = *px;
    
    *px = *py;
    *py = temp;
}

int main(void)
{
    int a, b;
    printf("스왑하고 싶은 정수 두 개를 a b 순서대로 입력하시오:");
    scanf("%d %d", &a, &b);
    
    printf("입력된 값 -> a: %d / b: %d\n", a, b);
    pointerSwap(&a, &b); // 주소를 추출한다.
    printf("스왑된 값 -> a: %d / b: %d\n", a, b);
}