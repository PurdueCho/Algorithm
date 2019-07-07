#include <iostream>

using namespace std;

int arr[1001];

void quickSort(int * data, int start, int end) {
    if (start >= end) {
        return;
    }

    int p = start;
    int i = start+1;
    int j = end;
    int temp;

    while ( i <= j ) {
        while ( data[i] <= data[p] ) {
            i++;
        }
        while ( data[j] >= data[p] && j > start ) {
            j--;
        }
        if (i > j) { // 엇갈림
            temp = data[p];
            data[p] = data[j];
            data[j] = temp;
        } else {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }

    quickSort(data, start, j-1);
    quickSort(data, j+1, end);

}

int main () {
    int N, i, j, temp;

    cin >> N;

    for (i = 0; i < N ; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, N-1);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}