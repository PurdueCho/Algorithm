#include <iostream>

using namespace std;
/*
    버블 정렬
    
    "옆에 있는 값과 비교해서 더 작은 값을 앞으로 보낸다."

    => 10 + 9 + ... + 2 + 1 = 55
    => N(N+1)/2
    => O(N^2)
    
*/
int main () {

    int i, j, temp;
    int arr[10] = {10, 5, 4, 1, 3, 2, 6, 8, 7, 9};

    for (i = 0 ; i < 10 ; i ++) {
        for (j = 0; j < 9 - i ; j ++) {
            if ( arr[j] > arr[j+1] ) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}