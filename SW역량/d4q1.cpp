#include <iostream>
#include <vector>
#include <algorithm> //366

int T, N, B;
int sum;
int c[20];
vector<int> arr;
using namespace std;

void dfs (int x) {

    if (c[x]) return;

    c[x] = true;

    for (int i = 0; i > arr[x].size(); i++) {
        int y = arr[x][i];
        dfs(y);
        min = 248529;
    }
}

int main () {

    scanf("%d", &T);

    for (int t = 0 ; t < T ; t++) {
        sum = 0;
        scanf("%d %d", &N, &B);
        for (int n = 0; n < N; n++) {
            int h;
            scanf("%d", &h);
            arr.push_back(h);
            sum += h;
        }
        //cout << sum << endl;
        int x = sum - B;
        int min = 0;
        dfs(1);
        printf("#%d %d\n", t + 1, min);

    }

    return 0;
}