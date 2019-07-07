#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Dynamic Programming
    '하나의 문제는 단 한번만 풀도록 하는 알고리즘'

    단순 분할 정복 기법은 동일한 문제를 다시 푼다는 단점이 있어서 심각한 비효율성을 낳는다.
    ex) 피보나치의 경우 D[12] 를 3번이나 반족적으로 계산..

    DP의 가정
    1. 큰 문제를 작은 문제로 나눌 수 있다.
    2. 작은 문제에서 구한 정답은 그것을 포함하는 큰 문제에서도 동일하다. (중요)
    
    즉, 크고 어려운 문제가 있으면 그것을 먼저 잘게 나누어서 해결한 뒤에 처리하여
    나중에 전체의 답을 구하는 것.
    이 과정에서 '메모이제이션(Memoization)'이 사용된다.
    => 이미 계산한 결과는 배열에 저장함으로서 나중에 동일한 계산을 해야 할 때는 저장된 값을 단순히 반환하기만 하면 되는 것.

    규칙석을 찾아서 점화실을 세워라..!
*/

// int dp(int x) { // 이 경우 2^n 승 만큼의 시간이 소요 된다.
//     if(x==1) return 1;
//     if(x==2) return 1;
//     return dp(x-1) + dp(x-2);
// }

int d[100]; // 메모이제이션

int dp(int x) { // 이 경우 2^n 승 만큼의 시간이 소요 된다.
    if(x==1) return 1;
    if(x==2) return 1;
    if(d[x] != 0) return d[x]; // 구한 적이 있으면 배열에서 반환
    return d[x] = dp(x-1) + dp(x-2); // 없으면 배열에 저장
}

int main() {
    printf("%d\n", dp(30));
}
