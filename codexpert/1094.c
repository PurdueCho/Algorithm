#include <stdio.h>

int K, N;
int T[100 + 10];    // 걸린시간
char Z[100 + 10]; // 정답여부
int sol;

int holder;
int time = 210;

int Solve() {
    holder = K; 

    for (int i = 0 ; i < N; i++) {
        switch (Z[i])
        {
        case 'T':
            time -= T[i];
            if (time <= 0) return holder;
            holder = holder % 8 + 1;
            break;
        case 'F':
            time -= T[i];
            break;
        case 'P':
            time -= T[i];
            break;

        default:
            break;
        }
        if (time <= 0) return holder;
    }

    return holder;
}

int main(void)
{
    int i;

    // 입력받는 부분
    scanf("%d", &K);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("\n%d %c", &T[i], &Z[i]);
    }

    // 여기서부터 작성
    sol = Solve();

    // 출력하는 부분
    printf("%d", sol);

    return 0;
}