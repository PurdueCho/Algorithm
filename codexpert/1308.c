#include <stdio.h>
#include <stdlib.h>

int N, M;
int A[10000 + 10];
int total;
int max = 0;

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
        total += A[i];
        if (A[i] >= max) max = A[i];
    }

    scanf("%d", &M);
}

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int calculate(int num) {

	int sum = 0;
	for (int i = 0; i < N; i++) {
        sum += (A[i] < num)?A[i]:num;
	}

	if (sum <= M)
        return 1;

	return 0;

}


int Solve() {
    qsort(A, N, sizeof(int), compare);
    
    int start, end, mid, ret;
    start = 0;
    end = max;

    while (start <= end) {
        mid = (start + end)/2;

        if ( calculate(mid) ) {
            ret = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ret;

}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    if (total <= M) {
        ans = max;
    } else {
        ans = Solve();
    }


    printf("%d\n", ans); // 출력하는 부분
    return 0;
}