/*
Strongly Connected Component
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	128 MB	3449	1697	925	45.792%
문제
방향 그래프가 주어졌을 때, 그 그래프를 SCC들로 나누는 프로그램을 작성하시오.

방향 그래프의 SCC는 우선 정점의 최대 부분집합이며, 
그 부분집합에 들어있는 서로 다른 임의의 두 정점 u, v에 대해서 u에서 v로 가는 경로와 v에서 u로 가는 경로가 모두 존재하는 경우를 말한다.


예를 들어 위와 같은 그림을 보자. 
이 그래프에서 SCC들은 {a, b, e}, {c, d}, {f, g}, {h} 가 있다. 물론 h에서 h로 가는 간선이 없는 경우에도 {h}는 SCC를 이룬다.

입력
첫째 줄에 두 정수 V(1≤V≤10,000), E(1≤E≤100,000)가 주어진다. 
이는 그래프가 V개의 정점과 E개의 간선으로 이루어져 있다는 의미이다. 
다음 E개의 줄에는 간선에 대한 정보를 나타내는 두 정수 A, B가 주어진다. 이는 A번 정점과 B번 정점이 연결되어 있다는 의미이다. 
이때 방향은 A->B가 된다.

출력
첫째 줄에 SCC의 개수 K를 출력한다. 다음 K개의 줄에는 각 줄에 하나의 SCC에 속한 정점의 번호를 출력한다. 
각 줄의 끝에는 -1을 출력하여 그 줄의 끝을 나타낸다. 각각의 SCC를 출력할 때 그 안에 속한 정점들은 오름차순으로 출력한다. 
또한 여러 개의 SCC에 대해서는 그 안에 속해있는 가장 작은 정점의 정점 번호 순으로 출력한다.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

//항상 처음 방문하는 노드만 실행
int dfs(int x) {
    d[x] = ++id;
    s.push(x);
    
    int result = d[x];
    for(int i = 0 ; i< a[x].size(); i++) {
        int y = a[x][i];
        // 아직 방문하지 않은 이웃 노드인 경우
        if(d[y] == 0) result = min(result, dfs(y));
        // 방문은 했지만 아직 처리중인 이웃 노드인 경우
        else if (!finished[y]) result = min(result, d[y]);
    }

    // 부모노드가 자기 자신인 경우 SCC 를 형성
    if (result == d[x]) {
        vector<int> scc;
        while (1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if (t == x) break;
        }
        sort(scc.begin(), scc.end());
        SCC.push_back(scc);
    }
    // 자신의 부모값을 반환
    return result;
}

int main() {
    int v, e;
    scanf("%d %d", &v, &e);
    for (int i = 0; i < e; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
    }
    for (int i = 1; i <= v; i++) {
        if(d[i] == 0) dfs(i);
    }
    printf("%d\n", SCC.size());
    sort(SCC.begin(), SCC.end());
    for(int i = 0; i < SCC.size(); i++) {
        for(int j = 0; j < SCC[i].size(); j++) {
            printf("%d ", SCC[i][j]);
        }
        printf("-1\n");
    }
}