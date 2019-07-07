/*
문제
2×N 크기의 벽을 2×1, 1×2, 1×1 크기의 타일로 채우는 경우의 수를 구해보자.

입력
첫째 줄에 N(1 ≤ N ≤ 1,000,000)이 주어진다.

출력
첫째 줄에 경우의 수를 1,000,000,007로 나눈 나머지를 출력한다.
*/

/*
D[n] = 2*D[n-1] + 3*D[n-2] + (2*D[n-3] + 2*D[n-4] ... + 2D[0])

2차원 DP
*/

#include <iostream>

using namespace std;

long long int d[1000001][2]; // d[i][0] == 정답부분, d[i][1] == 추가 개수 부분
 
long long int dp (int x) {
    d[0][0] = 1;
    d[1][0] = 2;
    d[2][0] = 7;
    d[2][1] = 0;

    for (int i = 3; i <= x; i++) {
        d[i][1] = (d[i-1][1] + d[i-3][0])%1000000007; // 추가 갯수 부분
        d[i][0] = (3*d[i-2][0] + 2*d[i-1][0] + 2*d[i][1])%1000000007; // 점화식
    }
    return d[x][0]; // 정답 부분 리턴
}

// int dp(int x) {
//     if( x == 0) return 1;
//     if( x == 1) return 2;
//     if( x == 2) return 7;
//     if( d[x] != 0 ) return d[x];

//     int ret = (2 * dp(x - 1) + 3 * dp(x - 2));

//     for (int i = 3 ; i <= x ; i++) {
//         ret += (2 * dp(x - i)) % 1000000007; // dp 사용 가능!
//     }

//     return d[x] = ret%1000000007;
// }

int main() {

    int n;
    scanf("%d", &n);
    printf("%lld\n", dp(n));

    return 0;
}