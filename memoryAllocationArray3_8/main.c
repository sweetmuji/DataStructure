#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

// 10 크기 만큼의 동적 배열을 만들고 반환
int main(void)
{
    int* p; // int의 주소를 가리키는 포인터 p
    
    p = (int*)malloc(sizeof(int) * SIZE);
    
    if(p == NULL)
    {
        printf("메모리가 부족하여 동적 메모리를 할당할 수 없습니다!\n");
        exit(1);
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        p[i] = i;
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", p[i]);
    }
    
    free(p);
    return 0;
}