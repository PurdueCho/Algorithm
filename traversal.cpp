#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
    이진트리의 구현과 순회(Traversal) 방식 
    가장 많이 사용되는 비선형 자료구조는 이진트리 (Binary Tree)
    데이터의 탐색 속도 증진을 위해 사용하는 구조

    포인터를 사용해서 특정한 루트에서 자식노드로 접근할 수 있음
    => 완전 이진트리가 아닌 이진트리는 배열로 표현하기 어렵다.
    => 포인터를 사용하면 유동적으로 트리 자료구조를 활용 가능 

    하나의 노드에 방문했을 떄 다음의 순서를 따른다.
    1. 전위 순회(Preorder Traversal)
    (1) 먼저 자기 자신을 처리한다.
    (2) 왼쪽 자식을 방문한다.
    (3) 오른쪽 자식을 방문한다.

    2. 중위 순회(Inorder Traversal)
    (1) 왼쪽 자식을 방문한다.
    (2) 먼저 자기 자신을 처리한다.
    (3) 오른쪽 자식을 방문한다.

    3. 후위 순회(Postorder Traversal) // 수식을 컴퓨터가 해결할 때 좋음
    (1) 왼쪽 자식을 방문한다.
    (2) 오른쪽 자식을 방문한다.
    (3) 먼저 자기 자신을 처리한다.

*/

int number = 15;

// 하나의 노드 정보를 선언한다.
typedef struct node * treePointer;
typedef struct node {
    int data;
    treePointer leftChild, rightChild;
} node;

// 전위 순회
void preorder(treePointer ptr) {
    if (ptr) {
        cout << ptr->data << ' ';
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

// 중위 순회
void inorder(treePointer ptr)
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        cout << ptr->data << ' ';
        inorder(ptr->rightChild);
    }
}

// 후위 순회
void postorder(treePointer ptr)
{
    if (ptr)
    {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << ' ';
    }
}

int main( ) {

    node nodes[number +1];
    for (int i = 1; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    for(int i = 1; i <= number; i++) {
        if( i % 2 == 0) {
            nodes[i/2].leftChild = &nodes[i];
        }
        else {
            nodes[i/2].rightChild = &nodes[i];
        }
    }

    preorder(&nodes[1]);
    cout << endl;
    inorder(&nodes[1]);
    cout << endl;
    postorder(&nodes[1]);

    return 0;
}