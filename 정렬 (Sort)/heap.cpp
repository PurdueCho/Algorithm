#include <iostream>

using namespace std;

/*
    힙 정렬
    
    "힙을 이용해 데이터를 정렬."
    
    힙 (Heap)
    힙은 최솟값이나 최댓값을 빠르게 찾아내기 위해 완전 이진 트리 (Complete Binary Tree) 를 기반으로 하는 트리
    힙에는 최대힙과 최소힙이 존재하는데 최대힙은 '부모 노드'가 '자식 노드'보다 큰 힙이라고 할 수 있다.
    일단 힙 정렬을 하기 위해서는 정해진 데이터를 힙 구조를 가지로록 만들어야 한다.
    
    힙 정렬을 수행하기 위해서는 힙 생성 알고리즘 (Heapify Algorithm)을 사용한다.
    => 전체 트리를 힙 구조로 만드는 복잡도는 O(N*logN)
        => 실질적으로 O(N) 만큼에 끝낼 수 있다.
    => 힙 생성 알고리즘의 시간 복잡도는 O(logN) 이고 전체 데이터의 갯수가 N개이면
        시간 복잡도는 O(N*logN) 이다.
    => 즉, 힙 정렬 전체시간 복잡도는 O(N*logN + N) = O(N*logN) 이다.

    힙 정렬은 병합 정렬과 다르게 별도로 추가적인 배열이 필요하지 않다는 점에서 메모리 측면에서 몹시 효율적.
    또한, 항상 O(N*logN) 을 보장할 수 있다는 점에서 몹시 강력한 정렬 알고리즘.
    이론적으로는 퀵 정렬, 병합 절열보다 더 우위에 있다고 할 수 있지만, 단순 속도만 가지고 비교하면 퀵 정렬이 평균적으로 더 빠름
    때문에 일반적으로 힙 정렬이 많이 사용되지는 않다.    
*/

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};
int main() {
    // 먼저 전체 트리 구조를 최대 힙 구조로 바꾼다.
    for (int i = 1; i < number; i ++) {
        int c = i;
        do {
            int root = (c-1)/2;
            if(heap[root] < heap[c]) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            c = root;
        } while (c != 0);
    }

    // 크기를 줄여가며 반복적으로 힙을 구성
    for( int i = number -1; i >= 0; i--) {
        int temp = heap[0];
        heap[0] = heap[i];
        heap[i] = temp;
        int root = 0;
        int c = 1;
        do {
            c = 2 * root + 1;
            // 자식 중에 더 큰 값을 찾기
            if(heap[c] < heap[c+1] && c < i-1 ) {
                c++;
            }
            // 루트 보다 자식이 더 크다면 교환
            if(heap[root] < heap[c] && c < i) {
                int temp = heap[root];
                heap[root] = heap[c];
                heap[c] = temp;
            }
            root = c;
        } while ( c < i);
    }

    for (int i = 0; i < number; i++)
    {
        cout << heap[i] << " ";
    }
    return 0;
}