/*
상어의 저녁식사
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	3276	917	650	27.095%
문제
어떤 상어는 저녁식사로 서로를 먹는다. 모든 상어는 자신과 다른 상어의 크기, 속도, 지능을 수치로 나타낸 것을 알고 있다. 만약, 상어 A의 크기, 속도, 지능이 상어 B의 크기, 속도, 지능보다 크거나 같다면 상어 A는 상어 B를 먹을 수 있다. 그러나, 상어들의 왕 김재홍은 상어들이 많이 없어지는 것을 방지하기 위해서 한 상어가 최대 두 개의 상어만 먹을 수 있게 했다. 상어들은 김재홍의 말을 모두 듣는다.

N마리 상어의 크기, 속도, 지능이 주어졌을 때, 살아남을 수 있는 상어의 최솟값을 구하시오.

입력
첫째 줄에 상어의 마리 수 N이 주어진다. 이 값은 50보다 작거나 같은 자연수이다. 둘째 줄부터 각 상어의 크기, 속도, 지능의 정보가 주어진다. 이 값은 2,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 살아남을 수 있는 상어의 최솟값을 출력한다.
*/

#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int stat[MAX][3];
int d[MAX];
bool c[MAX];
int n;

bool dfs(int x) {
    for(int i = 0; i < a[x].size(); i++) {
        int y = a[x][i];
        if(c[y]) continue;
        c[y] = true;
        if(d[y] == 0 || dfs(d[y])) {
            d[y] = x;
            return true;
        }
    }
    return false;
}

int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n ; i++) {
        int a, b, c;
        scanf("%d %d %d", &stat[i][0], &stat[i][1], &stat[i][2]);
    }
    for (int i = 1; i <= n-1; i++) {
        for(int j = i +1 ; j <= n; j++) {
            if (stat[i][0] == stat[j][0] && stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2]) {
                a[i].push_back(j);
            } else if (stat[i][0] >= stat[j][0] && stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2]) {
                a[i].push_back(j);
            } else if (stat[i][0] <= stat[j][0] && stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2]) {
                a[j].push_back(i);
            }
        }
    }
    int count = 0;
    for (int k = 0; k < 2; k++) {
        for (int i = 1; i <= n; i++) {
            fill(c, c+MAX, false);
            if(dfs(i)) count++;
        }
    }
    printf("%d\n", n-count); // 남아있는 상어의 개수 = 전체 수 - 잡아먹힐 상어 수
    return 0;
}