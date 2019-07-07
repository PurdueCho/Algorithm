/*
    Floyd Warshall 
    모든 정점에서 모든 정점으로의 최단거리
    다익스트라는 가장 적은 비용을 하나씩 선택했다면, 플로이드 와셜은 '거쳐가는 정점'을 기준으로 알고리즘 수행

    플로이드 와샬은 '거쳐가는 정점'을 기준으로 최단 거리를 구하는 것


*/

#include <stdio.h>

int number = 4;
int INF = 1000000000;

// 자료 배열을 초기화 합니다.
int a[4][4] = {
    {0, 5, INF, 8},
    {7, 0, 9, INF},
    {2, INF, 0, 4},
    {INF, INF, 3, 0}
};

void floydWarshall() {
    // 결과 그래프를 초기화 합니다.
    int d[number][number];

    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            d[i][j] = a[i][j];
        }
    }

    // k = 거쳐가는 노드
    for (int k = 0; k < number; k++) {
        // i = 출발 노드
        for (int i = 0 ; i < number ; i++) {
            // j = 도착 노드
            for (int j = 0; j < number; j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    // 결과 
    for (int i = 0 ; i < number ; i ++) {
        for (int j = 0 ; j < number; j++) {
            printf("%d ", d[i][j]);
        }
        printf("\n");
    }
}

int main () {
    
    floydWarshall();
    return 0;
}


