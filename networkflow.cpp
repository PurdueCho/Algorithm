/*
    네트워크 플로우 (Network Flow)

    특정한 지점에서 다른 지점으로 데이터가 얼마나 많이 흐르고 있는가를 측정
    => 교통체증, 네트워크 데이터 전송 등의 분야

    표현 방식은 유량/용량
    최대 유량 문제..
    => 각 간선에 정해진 용량이 있을때 A에서 B로 최대로 보낼 수 있는 유량의 크기를 구하는 문제

    기본적으로 최대유량 문제는 단순하게 가능한 모든 경우의 수를 탐색하는 방법을 사용
    BFS를 이용하는게 일반적
    => 에드몬드 카프 알고리즘 (Edmonds-Karp)

    1. 현재 흐르고 있는 유량(Flow)을 모두 0으로 설정
    2. 이후 정해진 용량(Capacity) 안에서 가능한 용량의 양을 반복적으로 더한다.
    3. 음의 유량을 계산
        => 유량을 더해주는 과정에서 사실은 보이지 않게 반대로 가는 유량이 빼지고 있다?
        실제로는 불가능함 (-6/0 ..)
        남아있는 모든 가능한 경로를 더 찾아내기 위함

    최대 유량 알고리즘은 순서가 상관 없다.
    남아있는 양이 1이 넘으면 계속해서 흘려 보내주면 알아서 최적화가 이루어짐

    시간 복잡도는 O(VE^2)
*/

#include <iostream>
#include <vector>
#include <queue>

#define MAX 100
#define INF 1000000000

using namespace std;

int n = 6, result;
int c[MAX][MAX], f[MAX][MAX], d[MAX]; // capacity, flow, 방문여부
vector<int> a[MAX];

void maxFlow( int start, int end) {
    while(1) {
        fill(d, d+MAX, -1); // -1 방문하지 않음
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i<a[x].size(); i++) {
                int y = a[x][i];
                // 방문하지 않은 노드 중에서 용량이 남은 경우
                if(c[x][y] - f[x][y] > 0 && d[y] == -1) {
                    q.push(y);
                    d[y] = x; // 경로를 기억합니다.
                    if (y == end) break; // 도착지에 도달을 한 경우
                }
            }
        }
        // 모든 경로를 다 찾은 경우 탈출합니다.
        if(d[end] == -1) break;
        int flow = INF;
        // 거꾸로 최소 유량을 탐색합니다.
        for(int i = end; i != start; i = d[i]) {
            flow = min(flow, c[d[i]][i] - f[d[i]][i]);
        }
        // 최소 유량만큼 추가합니다.
        for(int i = end; i != start; i = d[i]) {
            f[d[i]][i] += flow;
            f[i][d[i]] -= flow; // 음의 유량
        }
        result += flow;
    }
}

int main() {

    a[1].push_back(2);
    a[2].push_back(1);
    c[1][2] = 12;

    a[1].push_back(4);
    a[4].push_back(1);
    c[1][4] = 11;

    a[2].push_back(3);
    a[3].push_back(2);
    c[2][3] = 6;

    a[2].push_back(4);
    a[4].push_back(2);
    c[2][4] = 3;

    a[2].push_back(5);
    a[5].push_back(2);
    c[2][5] = 5;

    a[2].push_back(6);
    a[6].push_back(2);
    c[2][6] = 9;

    a[3].push_back(6);
    a[6].push_back(3);
    c[3][6] = 8;

    a[4].push_back(5);
    a[5].push_back(4);
    c[4][5] = 9;

    a[5].push_back(3);
    a[3].push_back(5);
    c[5][3] = 3;

    a[5].push_back(6);
    a[6].push_back(5);
    c[5][6] = 4;

    maxFlow(1, 6);
    printf("%d\n", result);
    return 0;
}