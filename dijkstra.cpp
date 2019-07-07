/*
    다익스트라(Dijkstra) 알고리즘
    DP를 이용한 대표적인 최단경로 알고리즘
    => 최단거리는 여러개의 최단거리로 이루어져 있기 때문...

    즉, 현재까지 알고 있던 최단거리를 계속 갱신하는 알고리즘..
    1. 출발 노드를 설정한다.
    2. 출발 노드를 기준으로 각 노드의 최소비용을 저장한다.
    3. 방문하지 않은 노드 중 가장 비용이 적은 노드를 선택한다.
    4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신.
    5. 3~4의 반복


*/

#include <stdio.h>

int number = 6;
int INF = 1000000000;

// 전체 그래프를 초기화
int a[6][6] = {
    {0, 2, 5, 1, INF, INF},
    {2, 0, 3, 2, INF, INF},
    {5, 3, 0, 3, 1, 5},
    {1, 2, 3, 0, 1, INF},
    {INF, INF, 1, 1, 0, 2},
    {INF, INF, 5, INF, 2, 0},
};
bool v[6]; // 방문 여부 체크
int d[6]; // 최단 거리

// 가장 최소거리를 가지는 정점을 반환
int getSmallIndex () {
    int min = INF;
    int index = 0;
    for (int i = 0 ; i < number; i++) {
        if (d[i] < min && !v[i]) { // 3. 방문하지 않은 노드 중 가장 비용이 적은 노드를 선택한다.
            min = d[i];
            index = i;
        }
    }
    return index;
}

//다익스트라를 선형 함수로 수행하는 함수 O(N^2) .. 
//노드의 갯수는 많은데 간선은 적을 떄 치명적으로 비효율적..
//간편하고 빠르게 작성할때 주로 사용
void dijkstra(int start) {
    for (int i = 0 ; i < number; i++) {
        d[i] = a[start][i]; // 2. 출발 노드를 기준으로 각 노드의 최소비용을 저장한다.
    }
    v[start] = true;
    for (int i = 0 ; i < number - 2; i++) {
        int current = getSmallIndex();
        v[current] = true;
        for (int j = 0; j< 6; j++) {
            if(!v[j]) { //3. 방문하지 않은 노드 중 가장 비용이 적은 노드를 선택한다.
                if (d[current] + a[current][j] < d[j]) { // 4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소 비용을 갱신.
                    d[j] = d[current] + a[current][j];
                }
            }
        }
    }
}

int main() {
    dijkstra(0);
    for (int i = 0; i < number ; i ++) {
        printf("%d ", d[i]);
    }

    return 0;
}