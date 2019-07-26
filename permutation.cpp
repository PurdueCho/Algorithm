/*
    순열 알고리즘
ex) P2 순열에서
(depth 0) 1XXX이 만들어지면,
(depth 1) 2XXX를 만드는것이 아니라 12XX 13XX 14XX 를 만들고
(depth 2) 바로 다음으로 123X
(depth 3) 마지막으로 1234이 채워져지며
(depth 4) 출력한다.

*/

#include <iostream>

using namespace std;


void permutation (int arr[], int depth, int n, int k) {
    // depth 가 선택한 숫자의 갯수와 같아지면 출력 후 리턴
    if (depth == k) {
        for (int i = 0 ; i < k ; ++i) {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    for (int i = depth; i < n ; i++ ) {
        // 순열을 위한 스왑
        swap(arr[i], arr[depth]);

        // depth 를 1 증가시킨 후 재귀
        permutation (arr, depth + 1, n, k);

        // 전단계의 분기점에서의 배열의 순서를 기억하고 이를 초기화하는 작업
        swap(arr[i], arr[depth]);
    }
}

int main () {

    int arr[4] = {1, 2, 3, 4};
    permutation(arr, 0, 4, 4);

    return 0;
}