/*
    강한 결합 요소(Strongly Connected Component, SCC)
    강한 결합 요소란 그래프 안에서 '강하게 결합된 정점 집합'을 의미
    SCC 는 '같은 SCC에 속하는 두 정점은 서로 도달이 가능하다'는 특징이 있다.

    사이클이 발생하는 경우 무조건 SCC에 해당한다.
    => 무향 그래프라면 그 그래프 전체는 무조건 SCC이다.

    SCC를 추출하는 알고리즘
    타잔 알고리즘 (Tarjan's Algorithm)
    => 모든 정점에 대해 DFS를 수행하여 SCC를 찾는 알고리즘

    SCC는 위상정렬을 수행할 수 있다.

    시간 복잡도는 O(V+E)
*/

#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001

using namespace std;

int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;

//DFS 는 총 정점의 갯수만큼 실행
int dfs(int x) {
    d[x] = ++id; // 노드마다 고유한 번호를 할당
    s.push(x);  // 스택에 자기 자신을 삽입

    int parent = d[x];
    for (int i = 0 ; i < a[x].size(); i++) {
        int y = a[x][i]; // 인접한 노드
        // 방문하지 않은 이웃 
        // 해당 노드로 dfs 수행, 결과적으로 더 작은 값을 부모로 갱신
        if(d[y] == 0) parent = min(parent, dfs(y)); 
        // 처리 중인 이웃
        else if (!finished[y]) parent = min(parent, d[y]);
    }

    // 부모노드가 자기 자신인 경우
    if (parent == d[x]) {
        vector<int> scc;
        while(1) {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            finished[t] = true;
            if(t == x) break;
        }
        SCC.push_back(scc);
    }

    // 자신의 부모값을 반환
    return parent;
}

int main () {
    int v = 11;
    a[1].push_back(2);
    a[2].push_back(3);
    a[3].push_back(1);
    a[4].push_back(2);
    a[4].push_back(5);
    a[5].push_back(7);
    a[6].push_back(5);
    a[7].push_back(6);
    a[8].push_back(5);
    a[8].push_back(9);
    a[9].push_back(10);
    a[10].push_back(11);
    a[11].push_back(3);
    a[11].push_back(8);

    for(int i = 1; i <= v; i++) {
        if(d[i]==0) dfs(i);
    }
    printf("SCC의 갯수 : %d\n", SCC.size());
    for(int i = 0; i < SCC.size(); i++) {
        printf("%d번 째 SCC: ", i+1);
        for (int j=0; j < SCC[i].size(); j++) {
            printf("%d ", SCC[i][j]);
        }
        printf("\n");
    }
   
}