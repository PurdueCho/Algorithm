#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    Kruskal Algorithm (크루스칼 알고리즘) 
    가장 적은 비용으로 모든 노드를 연결하기 위한 알고리즘
    최소 비용 신장 트리,,
    ex) 여러 개의 도시가 있을 때 각 도시를 도로를 이용해 최소한의 비용으로 연결?

    모든 노드(n)를 연결하기 위해 필요한 최소한의 간선 갯수는 n-1 개

    간선을 거리가 짧은 순서대로 그래프에 포함시키면 어떨까?

    최소 비용 신장 트리 순서
        모든 간선들을 '거리(비용)'을 기준으로 먼저 오름차순 정렬을 수행,
    1. 정렬된 순서에 맞게 그래프에 포함
    2. 포함시키기 전에는 사이클 테이블을 확인
    3. 사이클을 형성하는 경우 간선을 포함하지 않는다. // 최소 비용 신장 트리에서는 사이클이 발생하면 안된다.

*/

// 부모 노드를 찾는 함수
int getParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;                                    // 부모노드가 자신과 같다면 x 를 반환
    return parent[x] = getParent(parent, parent[x]); // 재귀적으로 부모노드를 찾는다.
}

// 두 부모노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return 1;
    return 0;
}

// 간선 클래스 선언
class Edge {
    public:
        int node[2];
        int distance;
        Edge(int a, int b, int distance) {
            this->node[0] = a;
            this->node[1] = b;
            this->distance = distance;
        }
        bool operator <(Edge &edge) {
            return this->distance < edge.distance;
        }
};

bool compare(Edge a, Edge b) {
    return a.distance < b.distance;
}

int main()
{
    int n = 7;
    int m = 11;

    vector<Edge> v;
    v.push_back(Edge(1, 7, 12));
    v.push_back(Edge(1, 4, 28));
    v.push_back(Edge(1, 2, 67));
    v.push_back(Edge(1, 5, 17));
    v.push_back(Edge(2, 4, 24));
    v.push_back(Edge(2, 5, 62));
    v.push_back(Edge(3, 5, 20));
    v.push_back(Edge(3, 6, 37));
    v.push_back(Edge(4, 7, 13));
    v.push_back(Edge(5, 6, 45));
    v.push_back(Edge(5, 7, 73));
    
    // 간선의 비용을 기준으로 오름차순 정렬
    sort(v.begin(), v.end(), compare);

    // 각 정점이 포함된 그래프가 어디인지 저장
    int parent[n];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        // 사이클이 발생하지 않는 경우 그래프에 포함
        if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
            sum += v[i].distance;
            unionParent(parent, v[i].node[0] -1, v[i].node[1] -1);
        }
    }

    printf("%d\n", sum);

    return 0;
}