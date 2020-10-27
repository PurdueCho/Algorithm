#include <stdio.h>
#include <math.h>

int N;
int a[14 + 10];
int sol;

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
    int A[N / 2 + 1], B[(int)(N - (N / 2))]; // A < B
    int a_idx = 0, b_idx = 0;
    int zero = 0;

    // 분류
    for (int i = 0; i < N ; i++) {

        // 0
        if (a[i] == 0) {
            zero++;
            //printf("%d. zero: %d\n", i, zero);
            continue;
        }

        if (a[i] != 0 && zero > 0) {
            //printf("%d. a[i], a[i+1]: %d %d\n", i, a[i], a[i+1]);
            A[a_idx++] = a[i+1];
            B[b_idx++] = a[i];
            while (zero > 0)
            {
                B[b_idx++] = 0;
                zero--;
                if (zero == 0) {
                    i++;
                    break;
                }
                //printf("%d. zero: %d\n", i, zero);
                A[a_idx++] = 0;
                zero--;
                //printf("%d. zero: %d\n", i, zero);
                i++;
            }
            
        } 
        else {
            //printf("%d. cur: %d\n", i, a[i]);
            if (i % 2 == 0)
                B[b_idx++] = a[i];
            else
                A[a_idx++] = a[i];
        }

        
    }


    for (int i = 0; i < N/2; i++){
        printf("%d", A[i]);
    }
    printf("\n");
    for (int i = 0; i < N - (N/2); i++){
        printf("%d", B[i]);
    }

    // Calculate
    int A_sum = 0, B_sum = 0;

    int p = 0;
    for (int i = N/2 - 1; i >= 0; i--) {
        A_sum += A[i] * pow(10, p++);
    }

    p = 0;
    for (int i = N - (N/2) - 1; i >= 0; i--) {
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