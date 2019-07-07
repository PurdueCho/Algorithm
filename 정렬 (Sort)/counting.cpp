#include <iostream>

using namespace std;

/*
    계수 (counting) 정렬
    
    "크기를 기준으로 갯수를 센다."
    
    범위 조건이 있는 경우에 한해서 굉장히 빠른 알고리즘 (크기를 기준으로)
    => O(N)
*/

int main () {
    int temp;
    int count[5] = {0,};
    int array[30] = {
        1, 3, 2, 2, 2, 3, 4, 5, 5, 4,
        4, 3, 2, 1, 1, 3, 4, 5, 4, 2,
        3, 4, 2, 2, 1, 1, 5, 4, 4, 5
    };

    for (int i = 0; i < 30; i++)
    {
        count[array[i] - 1] += 1;
    }

    for (int i = 0; i < 5; i++)
    {
        if (count[i] != 0) {
            for (int j = 0 ; j < count[i]; j++) {
                cout << i + 1 << " ";
            }
        }
    }
    return 0;
}