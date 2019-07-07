/*
문제
3×N 크기의 벽을 2×1, 1×2 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 30)이 주어진다.

출력
첫째 줄에 경우의 수를 출력한다.
*/

/*
n-2 일 경우 경우의 수 = 3 => 3*D[n-2]
n-4 부터 짝수개 마다 2개씩 추가 => 2*D[n-4] + 2*D[n-6] + ... + 2*D[0]
*/

#include <stdio.h>

int d[1001];

int dp (int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    if (n == 2) return 3;
    if(d[n] != 0) return d[n];

    int ret = 3*dp(n-2); // n-2 의 경우의 수 

    for (int i = 3; i <= n; i++) {  // 4 부터 짝수개 마다 2개씩 증가
        if (i % 2 == 0) {
            ret += 2*dp(n-i);
        }
    }
    return d[n] = ret;
}

int main (void) {

    int n;
    scanf("%d", &n);
    printf("%d\n", dp(n));

}