#include <iostream>

using namespace std;
/*
    퀵 정렬
    
    "특정한 값을 기준으로 큰 숫자와 작은 숫자를 나눈다."

    기본적으로 분할정복 알고리즘을 사용
    기본값 = 피벗 (Pivot)

    => N ^ 2 = 10 * 10 = 100
        1 2 3 4 5   => 5*5 = 25
        6 7 8 9 10  => 5*5 = 25
        큰수와 작은수로 나눠서 계산하면 훨씬 적은 수의 연산
    => 평균적으로 O(N*logN)
    => 최악의 경우 O(N^2) 
    
*/

int number = 10;
int data[10] = {1,10,5,8,7,6,4,3,2,9};

void quickSort ( int * data , int start, int end) {
    if (start >= end ) { // 원소가 1개인 경우
        return; 
    }

    int pivot = start; // 첫번째 원소
    int i = start + 1; // 왼쪽 출발지점
    int j = end;       // 오른쪽 출발지점
    int temp;

    while (i <= j) { // 엇갈릴 때까지 반복
        while ( data[i] <= data[pivot] ) { // 피벗보다 큰 값을 만날 때 까지 오른쪽으로 이동
            i++;
        }
        while ( data[j] >= data[pivot] && j > start ) { // 피벗보다 작은 값을 만날 때까지 왼쪽으로 이동
            j--;
        }
        if ( i > j ) { // 엇갈렸을 경우 피벗 값을 바꿔줌
            temp = data[pivot];
            data[pivot] = data[j];
            data[j] = temp;
        } else { // 아닐 경우 큰값과 작은값을 교환
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j-1);
    quickSort(data, j+1, end);
}


int main()
{
    quickSort(::data, 0 , number-1);

    for (int i = 0; i < 10; i++)
    {
        cout << ::data[i] << " ";
    }

    return 0;
}