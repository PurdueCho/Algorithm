#include <stdio.h>
#include <stdlib.h>

int N;
int X[100 + 10];
int Y[100 + 10];

typedef struct  {
    int x, y;
}CHEMS;

CHEMS chems[100+10];
int t[10000 + 270 + 1];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &chems[i].x, &chems[i].y);
    }
}

void Test() {
    for (int i = 0 ; i < 10271; i++) { 
        printf("%d", t[i]);
    }
    printf("\n");
}

int compare (const void * a, const void * b)
{
  if ( *(int*)a <  *(int*)b ) return 1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return -1;
}

int Solve() {
    int a, b;
    for (int i = 0; i < N; i++) {
        a = chems[i].x + 270;
        b = chems[i].y + 270;
        for (a = chems[i].x + 270; a < b; a++)
        {
            t[a]++;
        }
    }
    qsort(t, 10271, sizeof(t[0]), compare);
    Test();

    int total = 0;
    int count = 0;
    int idx = 0;

    while (total != N) {
        if (total + t[idx] <= N) {
            total += t[idx];
            count++;
            //printf("total: %d\n", total);
        }
        idx++;
    }

    //printf("count: %d\n", count);
    return count;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분
    
    // 여기서부터 작성
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}
