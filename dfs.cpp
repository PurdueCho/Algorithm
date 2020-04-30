#include <iostream>
#include <vector>

using namespace std;

/*
    깊이 우선 탐색 (Depth First Search) BFS
    탐색을 할때 보다 깊은 것을 우선적으로 하여 탐색하는 알고리즘
    맹목적으로 각 노드를 탐색할 때 주로 사용

    너비우선탐색 - Queue
    깊이우선탐색 - Stack

    사실 스택을 사용하지 않아도 구현이 가능 (재귀로..)
    => 컴퓨터는 구조적으로 항상 스택의 원리를 사용하기 때문

    1. 스택의 최상단 노드를 확인한다.
    2. 최상단 노드에게 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문처리한다. 
    방문하지 않은 인접 노드가 없으면 스택에서 최 상단 노드를 뺀다.
    1, 2의 반복수행

*/

int number = 7;
int c[7]; // 방문처리를 위한 배열
vector<int> a[8];

void dfs(int x)
{
    if (c[x]) return; // 이미 방문했다면 리턴

    c[x] = true;    // 아니면 방문처리
    
    cout << x << ' ';
    for (int i = 0 ; i < a[x].size(); i++) { // 그리고 인접 노드 탐색
        int y = a[x][i];
        dfs(y); // 재귀 처리
    }

}

int main()
{
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

    dfs(1);

    return 0;
}
