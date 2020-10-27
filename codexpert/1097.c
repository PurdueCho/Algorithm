#include <stdio.h>

int N, B;
int min, max;

void Solve() {

    // B/(N-1)
    double remain = (double) B / (double) (N-1); // 남은 상환금액
    
    int total = (int) (remain * N); // 최대 총액

    max = total;
    
    //printf("%lf\n", remain);

    double temp = remain - (int) remain;
    
    if (temp > 0) { // 정수 x
        min = max;
    } else if (temp == 0) {
        min = max -1;
    }

}

int main(void)
{
    // 입력받는 부분
    scanf("%d %d", &N, &B);

    // 여기서부터 작성
    Solve();
    // 출력하는 부분
    printf("%d %d", min, max);

    return 0;
}