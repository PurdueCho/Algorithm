#include <stdio.h>
#include <math.h>

int N;
int a[14 + 10];
int sol;
int A[14];
int B[14];

void Sorting() {
    for (int i = 0 ; i < N ; i ++) {
        for (int j = 0 ; j < N ; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}


int Solve() {
    
    int zero = 0;
    int arrIdx = 0;

    for (int i = 0; i < N; i++)
    {
        if (a[i] == 0)
            zero++; // index
        
    }
    //printf("%d\n", zero);

    // 처음
    A[0] = a[zero];
    B[0] = a[zero+1];
    int aIdx = 1, bIdx = 1;
    arrIdx = zero + 2; // arr idx

    // 0 채움
    while (zero != 0) {
        A[aIdx++] = 0;
        zero--;
        if (zero == 0) break;
        B[bIdx++] = 0;
        zero--;
    }

    // 나머지 채움
    for (int i = arrIdx ; i < N; i++) {
        if (i % 2 == 0) A[aIdx++] = a[i];
        else B[bIdx++] = a[i];
    }

    // for (int i = 0; i < aIdx; i++){
    //     printf("%d", A[i]);
    // }
    // printf("\n");
    // for (int i = 0; i < bIdx; i++){
    //     printf("%d", B[i]);
    // }
    // printf("\n");

    // Calculate
    int A_sum = 0, B_sum = 0;

    int p = 0;
    for (int i = aIdx -1; i >= 0; i--) {
        A_sum += A[i] * pow(10, p++);
    }

    p = 0;
    for (int i = bIdx-1; i >= 0; i--) {
        B_sum += B[i] * pow(10, p++);
    }

    //printf("%d %d\n", A_sum, B_sum);

    return A_sum + B_sum;


}

int main(void)
{
    int i;

    // 입력받는 부분
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    // 여기서부터 작성
    Sorting();
    sol = Solve();

    // 출력하는 부분
    printf("%d", sol);

    return 0;
}