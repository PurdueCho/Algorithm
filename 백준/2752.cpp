#include <iostream>

using namespace std;

int arr[3];

int main () {
    int i, j, index, min, temp;

    for (i = 0; i <3; i++) cin >> arr[i];

    for (i = 0; i < 3; i++)
    {
        min = 1000001;
        for (j = i; j < 3; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}