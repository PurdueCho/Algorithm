/*
문제
농부 John씨는 그의 소 축사를 갓 완성하였다. 축사 환경을 쾌적하게 유지하기 위해서, John씨는 축사를 N개의 칸으로 구분하여 두고, 한 칸에는 한 마리의 소만을 들어가도록 하였다.

첫 주에는 소들을 임의적으로 칸에 배정하여 축사를 운영하였으나, 곧 문제가 발생하게 되었다. 자신들이 희망하는 몇 개의 축사 외에는 들어가기를 거부하는 것이다.

농부 John씨를 도와 최대한 많은 수의 소가 축사에 들어갈 수 있도록 하는 프로그램을 작성하시오. 축사의 번호는 1부터 M까지 매겨져 있다고 한다.

입력
첫째 줄에 소의 마릿수 N과 축사의 개수 M이 주어진다. (1<=N<=200, 1<=M<=200)

둘째 줄부터 N개의 줄에는 N마리의 소들이 각자 들어가기 원하는 축사에 대한 정보가 주어진다. i번째 소가 들어가기 원하는 축사의 수 Si(0<=Si<=M)가 먼저 주어지고, 그 이후에 Si개의 축사 번호가 주어진다. 한 축사가 2번 이상 입력되는 경우는 없다.

출력
첫째 줄에 축사에 들어갈 수 있는 소 마릿수의 최댓값을 출력한다.
*/

#include <iostream>
#include <vector>
#define MAX 201

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m , s;

// 매칭에 성공하면 True, 실패한 경우 False
bool dfs(int x) {
    // 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
    for (int i = 0; i < a[x].size(); i++) {
        int t = a[x][i];
        // 이미 처리한 노드는 더이상 볼 필요가 없음
        if(c[t]) continue;
        c[t] = true;
        // 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if(d[t] == 0 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i++) {
        scanf("%d", &s);
        for(int j = 1; j <= s; j++) {
            int t;
            scanf("%d", &t);
            a[i].push_back(t);
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) {
        //최대한 우겨 넣습니다.
        fill(c, c+MAX, false);
        if(dfs(i)) count++;
    }
    printf("%d\n", count);
}