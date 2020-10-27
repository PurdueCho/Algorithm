#include <stdio.h>
#include <stdlib.h>

int N;
int A[1000 + 10];
void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second)
        return 1;
    else if (*(int *)first < *(int *)second)
        return -1;
    else
        return 0;
}

void Test() {

    for (int i = 0; i < N ; i++) {
        printf("%d", A[i]);
    }
    printf("\n");

}

int Solve() {
    int res = 0;
    if (A[0] != 1) return 1;

    for (int i = 0; i < N; i++)
    {
        if (A[i] > res + 1)
        {
            break;
        }
        res += A[i];
    }

    return res + 1;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    qsort(A, N, sizeof(int), compare);
   // Test();
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}