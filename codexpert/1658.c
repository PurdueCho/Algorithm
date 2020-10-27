#include <stdio.h>

int N, D, K, C;
int A[3000000 + 10]; // 회전 초밥 벨트
int sushi[3000 + 10]; // 초밥 종류

int max;

void InputData(void)
{
    scanf("%d %d %d %d", &N, &D, &K, &C);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
}

int Calculate() {
    int count = 0;
    
    for (int i = 1 ; i <= D+1; i++) {
        //printf("%d ", sushi[i]);
        if (sushi[i] != 0) count++;
    }
    //printf("\n%d\n", count);
    return count;
}

void Test() {
    for (int i = 1 ; i <= D+1; i++) {
        printf("%d ", sushi[i]);
    }
    printf("\n");
}

void Solve() {
    int idx = 0;
    int count = 0;
    // 처음
    for (int i = 0; i < K ; i++) {
        if (sushi[A[i] + 1] == 0) {
            count++;  
        }
        sushi[A[i] + 1]++;
    }


    // 쿠폰
    if (sushi[C + 1] == 0)
    {
        count++;
    }
    sushi[C + 1] ++;

    //Test();
    //printf("Count: %d\n", count);
    max = count;

    
    // Window Slide
    int pre, end;


    for (int i = 1 ; i < N ; i++) {
        pre = (i - 1) % N;

        end = (i + K - 1) % N;

        sushi[A[pre] + 1]--; // pre
        if (sushi[A[pre] + 1] == 0) count--;
        
        sushi[A[end] + 1]++; // end;
        if (sushi[A[end] + 1] != 0) count++;


        //Test();
        //printf("Count: %d\n", count);
        //printf("%d\n", Calculate());
        int temp = Calculate();
        if (max < temp) max = temp;
    }
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();
    ans = max; 

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}