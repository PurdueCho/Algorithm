#include <iostream>

using namespace std;

/*
    Union-Find (유니온 파인드) 
    '합집합 찾기' 라는 의미를 가진 그래프 알고리즘 (서로소 집합 Disjoint-Set 알고리즘)
    
    구체적으로 여러개의 노드가 존재할 때 두개의 노드를 선택해서, 현재 이 두 노드가 서로 같은 그래프에 속하는지 판별

    Find 알고리즘은 두 개의 노드의 부모 노드를 확인하여 현재 같은 집합에 속하는지 확인하는 알고리즘

    부모를 합칠때는 일번적으로 더 작은값 쪽으로 합친다. 합침(Union) 

    고급 그래프 알고리즘의 베이스가 된다.
    후에 크루스칼 알고리즘으로 연결됨
*/


// 부모 노드를 찾는 함수
int getParent (int parent[], int x) {
    if (parent[x] == x) return x; // 부모노드가 자신과 같다면 x 를 반환
    return parent[x] = getParent(parent, parent[x]); // 재귀적으로 부모노드를 찾는다.
}

// 두 부모노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b) return 1;
    return 0;
}

int main () {
    int parent[11];
    for (int i = 1; i <= 10; i++) {
        parent[i] = i;
    }
    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);
    unionParent(parent, 5, 6);
    unionParent(parent, 6, 7);
    unionParent(parent, 7, 8);

    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));

    unionParent(parent, 1, 5);

    printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));

    return 0;
}