/*
    위상 정렬 Topology Sort
    '순서가 정해져있는 작업'을 차례로 수행해야 할 때 그 순서를 결정해주기 위해 사용

    대학생 되기 -> 학과 사이트 가입 -> 4학년 되기 
    -> 정보처리 기사 합격 -> 자격 서류 제출
    -> 졸업시험 신청 -> 졸업하기
    위와 같이 정렬을 하면 순서대로 작업을 수행했을때 성공적으로 '졸업하기'까지 갈 수 있다.
    여러개의 답이 존재할 수 있다.
    
    위상 정렬은 DAG(Directed Acyclic Graph)에만 적용 가능하다.
    => 사이클이 발생하지 않는 방향 그래프..
    사이클이 발생하는 경우 위상정렬을 수행할 수 없다.

    위상정렬은 두가지 해결책을 낸다는 특징이 있다.
    1. 현재 그래프는 위상정렬이 가능한지
    2. 가능하다면 그 결과는 무엇인지

    큐를 이용한 순서
    1. 진입차수가 0인 정점을 큐에 삽입합니다.
    2. 큐에서 원소를 꺼내 연결된 모든 간선을 제거
    3. 간선 제거 이후 진입차수가 0이 된 정점을 큐에 삽입
    4. 큐가 빌 때까지 2번~3번 과정을 반족.
    => 모든 원소를 방문하기 전에 큐가 빈다면 사이클이 존재,
    모든 원소를 방문했다면, 큐에서 꺼낸 순서가 위상 정렬의 결과

    위상 정렬의 시간 복잡도는 O(V+E)
    즉, 정점의 갯수 + 간선의 갯수
    매우 빠른 알고리즘
*/

#include <iostream>
#include <vector>
#include <queue>
#define MAX 10

using namespace std;

int n, inDegree[MAX];
vector<int> a[MAX];

void topologySort() {
    int result[MAX];
    queue<int> q;
    //진입 차수가 0인 노드를 큐에 삽입
    for (int i = 1; i <= n; i++) {
        if(inDegree[i] == 0) q.push(i);
    }
    // 위상 정렬이 완전히 수행되려면 정확히 N개의 노드를 방문해야 함
    for(int i = 1; i <= n; i++) {
        // n개를 방문하기 전에 큐가 빈다면 사이클이 발생한 것
        if(q.empty()) {
            printf("t사이클이 발생했습니다.\n");
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for(int i = 0; i < a[x].size(); i++) {
            int y = a[x][i];
            // 새롭게 진입차수가 0이 된 정점을 큐에 삽입한다.
            if(--inDegree[y] == 0) {
                q.push(y);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", result[i]);
    }
}

int main () {
    n = 7;
    a[1].push_back(2);
    inDegree[2]++;
    a[1].push_back(5);
    inDegree[5]++;
    a[2].push_back(3);
    inDegree[3]++;
    a[3].push_back(4);
    inDegree[4]++;
    a[4].push_back(6);
    inDegree[6]++;
    a[5].push_back(6);
    inDegree[6]++;
    a[6].push_back(7);
    inDegree[7]++;

    topologySort();
}

