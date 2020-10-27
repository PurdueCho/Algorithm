#include <stdio.h>
#include <stdlib.h>

int N;            //연잎수
int A[1000 + 10]; //연잎좌표

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void printTest() {
    for (int i = 0 ; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int low_BS (int start, int end, int target) {
    int low, high, mid;
    int ret = -1;
    int lower, upper;

    // lower
    low = start; 
    high = end;

    while (low <= high) {
        mid = (low+high)/2;
    
        if (A[mid] >= target) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ret;
}

int upper_BS (int start, int end, int target) {
    int low, high, mid;
    int ret = -1;
    int lower, upper;

    //upper
    low = start;
    high = end;

    while (low <= high) {
        mid = (low+high)/2;

        if (A[mid] <= target) {
            ret = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ret;
}

int Solve() {
    int count = 0;
    // 1차 점프
    int dist = 0;
    int lower, upper;

    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1 ; j < N - 1; j++) {
            dist = A[j] - A[i];     // 1차 점프 거리
            // 2차 점프 D <= next <= 2*D
            lower = low_BS(0, N-1, A[j]+dist);
            upper = upper_BS(0, N-1, A[j] + 2*dist);
            if (lower == -1) break;         // 점프 할 곳 없음
            count += upper - lower + 1;     // 구간의 개수
        }
    }

    return count;
}

int main(void)
{
    int ans = -1;
    InputData(); //입력받는부분

    //여기서부터작성
    qsort(A, N, sizeof(int), compare);
    //printTest();
    
    ans = Solve();

    printf("%d\n", ans); //출력하는부분
    return 0;
}