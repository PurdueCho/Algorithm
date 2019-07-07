/*
문제
강호네 회사에는 직원이 N명이 있고, 해야할 일이 M개가 있다. 직원은 1번부터 N번까지 번호가 매겨져 있고, 일은 1번부터 M번까지 번호가 매겨져 있다.

각 직원은 한 개의 일만 할 수 있고, 각각의 일을 담당하는 사람은 1명이어야 한다. 단, N명 중에서 K명은 일을 최대 2개할 수 있다.

각각의 직원이 할 수 있는 일의 목록이 주어졌을 때, M개의 일 중에서 최대 몇 개를 할 수 있는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 직원의 수 N과 일의 개수 M, 일을 2개할 수 있는 직원의 수 K가 주어진다. (1 ≤ N, M ≤ 1,000, 1 ≤ K ≤ N)

둘째 줄부터 N개의 줄의 i번째 줄에는 i번 직원이 할 수 있는 일의 개수와 할 수 있는 일의 번호가 주어진다.

출력
첫째 줄에 강호네 회사에서 할 수 있는 일의 개수를 출력한다.
*/

#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
int d[MAX];
bool c[MAX];
int n, m, s, k;

// 매칭에 성공하면 True, 실패한 경우 False
bool dfs(int x)
{
    // 연결된 모든 노드에 대해서 들어갈 수 있는지 시도
    for (int i = 0; i < a[x].size(); i++)
    {
        int t = a[x][i];
        // 이미 처리한 노드는 더이상 볼 필요가 없음
        if (c[t])
            continue;
        c[t] = true;
        // 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
        if (d[t] == 0 || dfs(d[t]))
        {
            d[t] = x;
            return true;
        }
    }
    return false;
}

int main(void)
{
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s);
        for (int j = 1; j <= s; j++)
        {
            int t;
            scanf("%d", &t);
            a[i].push_back(t);
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        //최대한 우겨 넣습니다.
        fill(c, c + MAX, false);
        if (dfs(i))
            count++;
    }

    // 2번씩 작업할 수 있는 사람을 추가적으로 계산
    int extra = 0;
    for (int i = 1; i <= n && extra < k; i++) {
        fill(c, c+MAX, false);
        if(dfs(i)) extra++;
    }
    
    printf("%d\n", count + extra);
}