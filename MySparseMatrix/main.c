#include <stdio.h>

#define MAX_TERMS 100
typedef struct {
    int row; // 행
    int col; // 열
    int value; // 값
} element; // 행렬의 한 요소

typedef struct {
    element data[MAX_TERMS];
    
    int rows; // 행의 갯수 
    int cols; // 열의 갯수 
    int terms; // 항의 갯수 ( 희소 행렬의 0이 아닌 갯수 )
} SparseMatrix; // 희소 행렬 구조체 

SparseMatrix matrix_transpose(SparseMatrix a) // 희소 행렬을 전치 행렬로 만든 뒤 정렬 하고 반환 함수
{
    SparseMatrix b; // 반환할 전치된 희소 행렬
    
    int bIndex = 0;
    // a와 같은 크기를 같는다. ( 단순 값을 전치했기 때문. )
    b.rows = a.rows;
    b.cols = a.cols;
    b.terms = a.terms;
    
    if(a.terms > 0) // 만약 항의 갯수가 0이상이라면 ( 0으로만 이루어진 행렬이 아니라면 )
    {
        for(int i = 0; i < a.cols; i++) // 한 열을 모두 검사하고 한 열에 전체 항의 값 갯수 만큼 탐색한다. ( 한 열에 모든 항이 있을 경우에 대비해서 )
        {
            for(int j = 0; j < a.terms; j++)
            {
                if(a.data[j].col == i) // 해당 열의 번호에 맞는 데이터가 있는 경우 ( 열 번호가 같은 경우 ) 
                {
                    b.data[bIndex].col = a.data[j].row;
                    b.data[bIndex].row = a.data[j].col;
                    b.data[bIndex].value = a.data[j].value;
                    
                    bIndex++;
                }
            }
        }
    }
    
    return b;
}

SparseMatrix addMatrix(SparseMatrix a, SparseMatrix b)
{
    
}

void printMatrix(SparseMatrix a)
{
    for(int i = 0; i < a.terms; i++)
    {
        printf("{%d, %d, %d} ", a.data[i].row, a.data[i].col, a.data[i].value);
    }
    printf("\n");
}

int main(void)
{
    SparseMatrix m = { {{0, 3, 7}, {1, 0, 9}, {1, 5, 8}, {3, 0, 6}, {3, 1, 5}, {4, 5, 1}, {5, 2, 2}}, 6, 6, 7};
    
    SparseMatrix result = matrix_transpose(m);
    printMatrix(result);
}
