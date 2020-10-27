#include <stdio.h>

int N;
double D[10000 + 10];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%lf", &D[i]);
    }
}

double Solve() {
    double val = 0;
    double max = -1;

    for (int i = 0 ; i < N; i++) {
        if (max < D[i]) max= D[i];
    }

    for (int i = 0 ; i < N-1; i++) {
        val = D[i];
        //printf("Cur: %.3lf\n", D[i]);
        for (int j = i+1; j < N; j++) {
            val *= D[j];
            //printf("Mul: %.3lf --> %.3lf\n", D[j], val);
            
            if (val > max)
                max = val;
        }
    }
    return max;
}

int main(void)
{
    double ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    printf("%.3lf\n", ans); // 출력하는 부분
    return 0;
}
