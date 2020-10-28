#include <stdio.h>
#include <stdlib.h>

int M, N, L;        // 사대의 수, 동물의 수, 사정거리
int X[100000 + 10]; // 사대의 위치
int A[100000 + 10]; // 동물의 x
int B[100000 + 10]; // 동물의 y

int total = 0;

typedef struct
{
    int x, y;
    int visit;
} DATA;

DATA data[100000 + 10];
//int map[100000 + 10][100000 + 10]; // 방문 체크

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void InputData(void)
{
    scanf("%d %d %d", &M, &N, &L);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &X[i]);
    }
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &data[i].x, &data[i].y);
        data[i].visit = 0;
    }
}

int BS(int num)
{
    int start, end, mid;
    int ret = -1;

    start = 0;
    end = M - 1;

    while (start <= end) {
        mid = (start + end) / 2;

        if (X[mid] <= num) {
            ret = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    
    return ret;
}

int Solve()
{
    int saro;
    int saro2;
    int dist;

    for (int i = 0 ; i < N; i++) {
        //  동물 가장 가까운 사로 찾기
        saro = BS(data[i].x);
        //printf("사로: %d\n", X[saro]);

        if (saro != -1) {
            dist = abs(X[saro] - data[i].x) + data[i].y;
            //printf("Dist: %d L: %d\n", dist, L);

            if (dist <= L)
            { // 거리가 L 보다 작거나 같은 위치
                data[i].visit = 1;
                //printf("dist. %d (X, Y): (%d, %d)\n", dist, data[i].x, data[i].y);
                total++;
            }
        }

        if (!data[i].visit) {   // 반대쪽 사로 체크
            saro2 = saro + 1;

            if (saro2 < M) {
                dist = abs(X[saro2] - data[i].x) + data[i].y;
                if (dist <= L)
                { // 거리가 L 보다 작거나 같은 위치
                    data[i].visit = 1;
                    //printf("dist. %d (X, Y): (%d, %d)\n", dist, data[i].x, data[i].y);
                    total++;
                }
            }
        }
    }

    return total;
}

void printMap()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d", data[i].visit);
        }
        printf("\n");
    }
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    //여기서부터 작성
    qsort(X, M, sizeof(int), compare); // 사대 정렬

    ans = Solve();
    //printMap();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}