#include <stdio.h>
#include <math.h>

typedef struct point {
    int x;
    int y;
} point;

float calc_distance(point a, point b)
{
    float distance;
    
    distance = sqrtf((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    return distance;
}

int main(void)
{
    point p1;
    point p2;
    
    p1.x = 1;
    p1.y = 2;
    
    p2.x = 9;
    p2.y = 8;
    
    printf("%f\n", calc_distance(p1, p2));
}