#include <stdio.h>
#include <stdlib.h>

int K;
int A[6 + 10];
int B[6 + 10];

int max = 0;
int idx = 0;

void InputData(void)
{
    scanf("%d", &K);
    for (int i = 0; i < 6; i++)
    {
        scanf("%d %d", &A[i], &B[i]);   // 방향, 길이 ¯
        if (B[i] > max) {
            max = B[i];
            idx = i;
        }
    }
}

int Solve() {

    int prev = (idx + 6 - 1) % 6;
    int next = (idx + 6 + 1) % 6;
    int total = 0;
    int sub = 0;
    int sub_a, sub_b;

    //printf("Max: %d at %d\n", max, idx);
    //printf("Comparing %d with %d --> %d %d\n", prev, next, B[prev], B[next]);
    if (B[prev] < B[next]) {
        //printf("total: %d x %d\n", B[idx], B[next]);
        total = B[idx] * B[next];

        //printf("Sub: %d x %d\n", B[(next + 2) % 6], B[(next + 3) % 6]);
        sub = B[(next + 2) % 6] * B[(next + 3) % 6];
    } else {
        //printf("total: %d x %d\n", B[idx], B[prev]);
        total = B[idx] * B[prev];

        //printf("Sub: %d x %d\n", B[(prev + 6 - 2) % 6], B[(prev + 6 - 3) % 6]);
        sub = B[(prev + 6 - 2) % 6] * B[(prev + 6 - 3) % 6];
    }

    return (total - sub) * K;

    
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