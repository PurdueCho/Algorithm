/*

문제
2×n 직사각형을 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.

*/

#include <iostream>

using namespace std;

int d[1001];


int dp(int n) {
    if (n == 1) return 1; // 1 일때 경우의 수 1
    if (n == 2) return 3; // 2 일때 경우의 수 3,, 3일 때 부터 반복 .. 점화식
    if (d[n] != 0) return d[n];
    return d[n] = (dp(n-1) + 2 * dp(n-2) )%10007;
}

int main () {

    int n;
    scanf("%d", &n);

    int ret = dp(n);

    printf("%d\n", ret);

    return 0;
}
