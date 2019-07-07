/*
도미노
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	256 MB	1627	466	331	28.559%
문제
도미노는 재밌다. 도미노 블록을 일렬로 길게 늘어세운 뒤 블록 하나를 넘어뜨리면 그 블록이 넘어지며 다음 블록을 넘어뜨리는 일이 반복되어 일렬로 늘어선 블록들을 연쇄적으로 모두 쓰러뜨릴 수 있다. 그러나, 가끔씩 도미노가 다른 블록을 넘어뜨리지 못하게 배치되어 있다면, 우리는 다음 블록을 수동으로 넘어뜨려야 한다.

이제 각 도미노 블록의 배치가 주어졌을 때, 모든 블록을 넘어뜨리기 위해 손으로 넘어뜨려야 하는 블록 개수의 최솟값을 구하자.

입력
첫 번째 줄에 테스트 케이스의 개수가 주어진다.

각 테스트 케이스의 첫 번째 줄에는 두 정수 N, M이 주어지며 두 수는 100,000을 넘지 않는다. N은 도미노의 개수를, M은 관계의 개수를 나타낸다. 도미노 블록의 번호는 1과 N 사이의 정수다. 다음 M개의 줄에는 각각 두 정수 x, y가 주어지는데, 이는 x번 블록이 넘어지면 y번 블록도 넘어짐을 뜻한다.

출력
각 테스트 케이스마다 한 줄에 정수 하나를 출력한다. 정답은 손으로 넘어뜨려야 하는 최소의 도미노 블록 개수이다.

강한 결합요소 + 강한결합요소 사이의 관계까지 구해야 함
강한 결합 요소 끼리는 일방향적으로 연결되어 있다는 점에서 위상 정렬을 수행할 수 있다.
도미노는 강한 결합요소를 정점으로 보고 위상정렬을 수행했을때 진입차수가 0 인 정점의 갯수를 세면 되는 문제
*/

#include <iostream>
#include <vector>
#include <stack>
#define MAX 100001

using namespace std;

int n, m;
int id, d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
int group[MAX];
bool inDegree[MAX];

//항상 처음 방문하는 노드만 실행
int dfs(int x)
{
    d[x] = ++id;
    s.push(x);

    int result = d[x];
    for (int i = 0; i < a[x].size(); i++)
    {
        int y = a[x][i];
        // 아직 방문하지 않은 이웃 노드인 경우
        if (d[y] == 0)
            result = min(result, dfs(y));
        // 방문은 했지만 아직 처리중인 이웃 노드인 경우
        else if (!finished[y])
            result = min(result, d[y]);
    }

    // 부모노드가 자기 자신인 경우 SCC 를 형성
    if (result == d[x])
    {
        vector<int> scc;
        while (1)
        {
            int t = s.top();
            s.pop();
            scc.push_back(t);
            group[t] = SCC.size() + 1; // 강한 결합 요소 그룹의 아이디 값..
            finished[t] = true;
            if (t == x)
                break;
        }
        SCC.push_back(scc);
    }
    // 자신의 부모값을 반환
    return result;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        // testcase 가 있으므로 초기화..
        SCC.clear();
        fill(d, d+MAX, 0);
        fill(finished, finished + MAX, 0);
        fill(inDegree, inDegree + MAX, false);
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            a[i].clear();
        }
        for (int i = 0; i< m ; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x].push_back(y);
        }
        for(int i = 1; i<=n; i++) {
            if(d[i] == 0) dfs(i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < a[i].size(); j++) {
                int y = a[i][j];
                if(group[i] != group[y]) {
                    // 진입차수가 존재
                    inDegree[group[y]] = true;
                }
            }
        }
        int result = 0;
        for (int i = 1; i <= SCC.size(); i++) {
            if(!inDegree[i]) result++;
        }
        printf("%d\n", result);
    }
    
}
