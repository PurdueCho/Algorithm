#include <iostream>

/*
    선택 정렬

    "제일 작은 수를 선택해서 가장 앞으로 보낸다."

    => 10 + 9 + ... + 2 + 1 = 55
    => N(N+1)/2
    => O(N^2)
*/

using namespace std;

int main () {

    int i, j, index, min, temp;
    int arr[10] = {10,5,4,1,3,2,6,8,7,9};

    for (i = 0 ; i < 10 ; i++) {
        min = 9999;
        for (j = i ; j < 10 ; j ++) {
            if (min > arr[j]) {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    
    for (int i = 0 ; i < 10 ; i++) {
        cout << arr[i] << " ";
    }

    return 0;

}