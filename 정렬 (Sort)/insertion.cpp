#include <iostream>

using namespace std;
/*
    삽입 정렬
    
    "각 숫자를 적절한 위치에 삽입한다."
    
    앞선 배열은 정렬이 되어있다는 것을 가정하기 때문에 특정한 경우 굉장히 빠른 속도를 보여준다.
    => 10 + 9 + ... + 2 + 1 = 55
    => N(N+1)/2
    => O(N^2)
    
*/
int main()
{

    int i, j, temp;
    int arr[10] = {10, 5, 4, 1, 3, 2, 6, 8, 7, 9};

    for (i = 0; i < 9 ; i++) {
        j = i;
        while ( arr[j] > arr[j+1] ) {
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}