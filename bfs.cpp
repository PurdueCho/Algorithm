#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    너비 우선 탐색 (Breadth First Search) BFS
    탐색을 할 때 너비를 우선으로 하여 탐색하는 탐색 알고리즘
    
    맹목적인 탐색을 하는데 특히 사용
    '최단 경로'를 찾아준다는 점에서 최단 길이를 보장해야 할 때 사용.
    
    1. 큐에서 하나의 노드를 꺼낸다.
    2. 해당 노드에 연결된 노드 중 방문하지 않은 노드를 방문하고 차례대로 큐에 삽입한다.
    1, 2 의 반복

*/

int number = 7;
int c[7]; // 방문처리를 위한 배열
vector<int> a[8];


void bfs(int start) {
    queue<int> q;
    q.push(start);
    c[start] = true;
    while ( !q.empty() ) {
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for (int i = 0; i < a[x].size(); i++) { // 현재 큐에서 꺼낸 원소와 인접한 노드들을 한번씩 방문
            int y = a[x][i];
            if (!c[y]) { // 방문을 한 상태면 무시, 아니라면 큐에 담아주고 방문표시
                q.push(y);
                c[y] = true;
            }
        }
    }
}

int main () {
    // 인접한 노드들을 나타낸 그래프 생성

    // 1 - 2 연결
    a[1].push_back(2);
    a[2].push_back(1);

    // 1 - 3 연결
    a[1].push_back(3);
    a[3].push_back(1);

    // 2 - 3 연결
    a[2].push_back(3);
    a[3].push_back(2);

    // 2 - 4 연결
    a[2].push_back(4);
    a[4].push_back(2);

    // 2 - 5 연결
    a[2].push_back(5);
    a[5].push_back(2);

    // 4 - 5 연결
    a[4].push_back(5);
    a[5].push_back(4);

    // 3 - 6 연결
    a[3].push_back(6);
    a[6].push_back(3);

    // 3 - 7 연결
    a[3].push_back(7);
    a[7].push_back(3);

    // 6 - 7 연결
    a[6].push_back(7);
    a[7].push_back(6);

    bfs(1);

    return 0;
}
