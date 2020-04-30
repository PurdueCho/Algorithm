/*
문제
N개의 정수로 이루어진 배열 A가 주어진다. 이때, 배열에 들어있는 정수의 순서를 적절히 바꿔서 다음 식의 최댓값을 구하는 프로그램을 작성하시오.

|A[0] - A[1]| + |A[1] - A[2]| + ... + |A[N-2] - A[N-1]|

입력
첫째 줄에 N (3 ≤ N ≤ 8)이 주어진다. 둘째 줄에는 배열 A에 들어있는 정수가 주어진다. 배열에 들어있는 정수는 -100보다 크거나 같고, 100보다 작거나 같다.

출력
첫째 줄에 배열에 들어있는 수의 순서를 적절히 바꿔서 얻을 수 있는 식의 최댓값을 출력한다. 

문제 풀이
순열을 이용해서 값을 구한 뒤 최대값을 찾는다
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;

int calc ( vector<int> v) {
    int sum = 0;
    for (int i = 1 ; i < v.size() ; ++i) {
        sum += abs(v[i] - v[i - 1]);
    }
    return sum;
}

int main () {
    int n;
    scanf("%d", &n);

    for (int i = 0 ; i < n ; ++i) {
        int d;
        scanf("%d", &d);
        v.push_back(d);
    }
    sort(v.begin(), v.end());

    int ret = 0;

    do {
        int temp = calc(v);
        ret = max(ret, temp);
    } while (next_permutation(v.begin(), v.end()));

    printf("%d", ret);

    return 0;
}