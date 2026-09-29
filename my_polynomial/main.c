#include <stdio.h>

#define MAX_TERMS 100

typedef struct polynomial {
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS] = { {8,3}, {7,1}, {1, 0}, {10, 30}, {4, 3}, {5, 0}};
int current_length;

int compare(int a, int b)
{
    if(a>b)
        return 0;
    else if(a<b)
        return 1;
    else if(a==b)
        return 2;
        
    // a 가 b 보다 크다면 0, 반대면 1, 같다면 2 반환
}

void attach(float coef, int expon)
{
    terms[current_length].coef = coef;
    terms[current_length].expon = expon;
    
    current_length++;
}

void poly_add(int as, int ae, int bs, int be, int* cs, int* ce)
{
    // as, bs 인덱스의 차수를 비교 한다. 
    // 만약 같다면 -> 계수를 더하고 attach ( lenght ++ )
    // A > B 라면 -> A 차수와 계수를 attach 하고 as++ ( length ++ )
    // A < B 라면 -> B 차수와 계수를 attach 하고 bs++ ( length ++ )
    // as <= ae 이고 bs <= be 일 때 까지
    
    *cs = current_length; // 덧셈을 시행 하기 전 최초의 끝 자리를 새로운 다항식의 시작점으로
    
    while ((as<=ae)&&(bs<=be))
    {
        if(compare(terms[as].expon, terms[bs].expon) == 0) // 차수가 a가 크다면 
        {
            attach(terms[as].coef, terms[as].expon);
            as++;
        }
        else if(compare(terms[as].expon, terms[bs].expon) == 1) // 차수가 b가 크다면 
        {
            attach(terms[bs].coef, terms[bs].expon);
            bs++;
        }
        else if(compare(terms[as].expon, terms[bs].expon) == 2) // 차수가 같다면
        {
            attach(terms[as].coef + terms[bs].coef, terms[as].expon); 
            as++;
            bs++;
        }
    }
    
    // 끊긴 지점 부터 끝까지 남은 값 집어넣기
    for(;as <= ae; as++)
        attach(terms[as].coef, terms[as].expon);
        
    for(;bs <= be; bs++)
        attach(terms[bs].coef, terms[bs].expon);
    
    *ce = current_length - 1;
}

void poly_print(int s, int e)
{
    for(int i = s; i < e; i++)
        printf("%.1fx^%d + ", terms[i].coef, terms[i].expon);
    printf("%.1fx^%d", terms[e].coef, terms[e].expon);
    
    printf("\n");
}

int main(void)
{
    current_length = 6; // 배열 길이 구하기
    int cs, ce;
    poly_add(0, 2, 3, 5, &cs, &ce);
    poly_print(0, 2);
    poly_print(3, 5);
    poly_print(cs, ce);
}