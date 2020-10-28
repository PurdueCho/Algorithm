#include <stdio.h>
#include <stdlib.h>

int M, N, L;               // 사대의 수, 동물의 수, 사정거리
int X[100000 + 10];     // 사대의 위치
int A[100000 + 10];     // 동물의 x
int B[100000 + 10];     // 동물의 y

int total = 0;

typedef struct {
    int x, y;
    int visit;
}DATA;

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

int check ( int num ) {

    int x, y;
    int dist = 0;
    int flag = 0;
    int saro = X[num];

    for (int i = 0; i < N ; i++) {
        x = data[i].x;
        y = data[i].y;

        //if (map[x][y] == 1) continue;   // 방문한 것은 건너뜀
        if (data[i].visit == 1) continue;

        dist = abs(saro - x) + y; // 거리

        if (dist <= L) {    // 거리가 L 보다 작거나 같은 위치
            //map[x][y] = 1;
            data[i].visit = 1;
            //printf("dist. %d (X, Y): (%d, %d)\n", dist, x, y);
            flag = 1;
            total++;
        }
    }

    return flag;
}

int Solve() {
    int x; // 사대 위치
    int start, end, mid;

    start = 0 ; end = M - 1;

    // for (int i = 0 ; i < M ; i++) {
    //     //printf("사로 %d 서칭 \n", X[mid]);
    //     check(i);
    // }

    while (start <= end) {
        mid = (start + end) / 2;

        printf("사로 %d 서칭 \n", X[mid]);
        if ( check (mid) == 1) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return total;
    
}

void printMap() {
    for (int i = 0; i < N ; i++) {
        for (int j = 0; j < N; j++) {
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
    qsort(X, M, sizeof(int), compare);  // 사대 정렬

    ans = Solve();
    //printMap();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}