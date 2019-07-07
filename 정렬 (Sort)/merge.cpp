#include <iostream>

using namespace std;

/*
    병합 정렬
    
    "일단 반으로 나누고 나중에 합쳐서 정렬한다."
    
    피벗 값이 없고 항상 반으로 나눈다.
    N 개 width의 data를 logN 만큼의 depth 로 처리
    => O(N*logN) 를 *보장*

    기본적으로 병합 정렬은 기존의 데이터를 담을 추가적인 배열 공간이 필요하다는 점에서 메모리 활용이 비효율적
    
*/

int number = 8;
int sorted[8]; // 정렬 배열은 반드시 전역변수로 선언해서 불필요한 메모리 낭비를 줄인다.

void merge(int a[], int m, int middle, int n) {
    int i = m;
    int j = middle + 1;
    int k = m;
    // 작은 순서대로 배열에 삽입
    while (i <= middle && j <= n) {
        if (a[i] <= a[j]) {
            sorted[k] = a[i];
            i++;
        } else {
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    // 남은 데이터도 삽입
    if (i > middle) {
        for (int t = j; t <= n; t++) {
            sorted[k] = a[t];
            k++;
        }
    } else {
        for (int t = i; t <= middle; t ++) {
            sorted[k] = a[t];
            k++;
        }
    }
    // 정렬된 배열을 삽입
    for (int t = m; t <= n; t++) {
        a[t] = sorted[t];
    }
}

void mergeSort (int a[], int m, int n) {
    // 크기가 1보다 큰 경우
    if (m < n) {
        int middle = (m+n)/2;
        mergeSort(a, m, middle);
        mergeSort(a, middle+1, n);
        merge(a, m, middle, n);
    }
}

int main () {
    int array[8] = {7, 6, 5, 8, 3, 5, 9, 1};
    mergeSort(array, 0, number -1);
    for (int i = 0; i < number; i++) {
        cout << array[i] << " ";
    }
    
    return 0;
}