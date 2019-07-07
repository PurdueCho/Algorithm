/*
    이분 매칭은 A 집단이 B 집단을 선택하는 방법에 대한 알고리즘

    최대 매칭을 의미
    네트워크 플로우와 정확히 일치
    => 각 용량(Capacity)를 1로 설정한 네트워크 플로우 문제라고 이해 가능
    DFS로 풀 수 있음
    => O(V*E)의 시간복잡도
*/

#include <iostream>
#include <vector>
#define MAX 101

using namespace std;

vector<int> a[MAX];
int d[MAX]; // 점유하고 있는 노드의 정보
bool c[MAX]; // 특정 노드를 점유했는지 확인
int n = 3, m;

// 매칭에 성공한 경우 True, 실패한 경우 False
bool dfs(int x) {
    // 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
    for (int i = 0; i < a[x].size(); i++) {
        int t = a[x][i];
        // 이미 처리한 노드는 더 이상 볼 필요가 없음
        if(c[t]) continue;
        c[t] = true;
        // 비어 있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if (d[t] == 0 || dfs(d[t])) {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void) {
    a[1].push_back(1);
    a[1].push_back(2);
    a[1].push_back(3);
    a[2].push_back(1);
    a[3].push_back(2);
    int count = 0;
    for (int i = 1; i <= n; i++) {
        fill(c, c + MAX, false); // 매번 초기화
        if(dfs(i)) count++;
    }
    printf("%d개의 매칭이 이루여졌습니다.\n", count);
    for (int i = 1; i < MAX ; i++) {
        if(d[i] != 0) {
            printf("%d -> %d \n", d[i], i);
        }
    }
    return 0;
}
