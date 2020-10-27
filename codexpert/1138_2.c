#include <stdio.h>
#include <stdlib.h>

int N;
int X[100 + 10];
int Y[100 + 10];

typedef struct {
    int x,y;
} CHEM;

CHEM C[100 + 10];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &C[i].x, &C[i].y);
    }
}

int comp(const void *a, const void *b)
{
    CHEM *x = (CHEM *)a;
    CHEM *y = (CHEM *)b;

    return x->y - y->y;
}

void Test() {
    for (int i = 0 ; i < N ; i ++) {
        printf("id: %d, %d %d\n", i, C[i].x, C[i].y);
    }
    printf("\n");
}

int Solve() {
    
    int end = C[0].y;
    int count = 1;

    for (int i = 1 ; i < N; i ++) {

        if (end < C[i].x) {
            count++;
            end = C[i].y;
        }

    }

    //printf("%d\n", count);
    return count;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    qsort(C, N, sizeof(C[0]),comp);
    //Test();
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}