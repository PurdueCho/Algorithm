/*
    KMP 알고리즘
    문자열 매칭 알고리즘
    => 특정한 글이 있을 때 그 글 안에서 하나의 문자열을 찾는 알고리즘

    단순 비교 문자열 매칭 알고리즘
    => 하나씩 확인하는 알고리즘
    O(N*M)의 시간복잡도

    KMP
    모든 경우를 다 비교하지 않아도 부분 문자열을 찾을 수 있음
    접두사와 접미사의 개념을 활용하여 '반복되는 연산을 얼마나 줄일 수 있는지'를 판별
    접두사와 접미가 일치하는 경우에 한해서는 점프가 가능..

    하나씩 접두사와 접미사를 늘려가며 비교하다가 일치하지 않는 경우가 발생하면,
    일치했던 부분까지 되돌아가서 다시 검사를 하는 방식..

*/

#include <iostream>
#include <vector>

using namespace std;

// 단순 비교 문자열 알고리즘
int findString(string parent, string pattern) {
    int parentSize = parent.size();
    int patternSize = pattern.size();
    for (int i = 0 ; i <= parentSize - patternSize; i++) {
        bool finded = true;
        for (int j = 0 ; j < patternSize; j++) {
            if (parent[i+j] != pattern[j]) {
                finded = false;
                break;
            }
        }
        if (finded) {
            return i;
        }
    }
    return -1;
}

// 실패 테이블
vector<int> makeTable(string pattern) {
    int patternSize = pattern.size();
    vector<int> table(patternSize, 0);
    int j = 0;
    for (int i = 1; i < patternSize; i++) {
        // 문자가 일치하지 않으면 j의 인덱스를 1 만큼 줄임
        while(j > 0 && pattern[i] != pattern[j]) { 
            j = table[j-1];
        }
        // 문자가 일치하면 j의 인덱스를 1 만큼 증가시킨후 테이블에 저장
        if(pattern[i] == pattern[j]) {
            table[i] = ++j;
        }
    }
    return table;
}

void KMP(string parent, string pattern) {
    vector<int> table = makeTable(pattern);
    int parentSize = parent.size();
    int patternSize = pattern.size();
    int j = 0;
    for (int i = 0; i < parentSize; i++) {
        while(j > 0 && parent[i] != pattern[j]) {
            j = table[j-1];
        }
        if(parent[i] == pattern[j]) {
            if (j == patternSize -1) {
                printf("%d번째에서 찾았습니다.\n", i-patternSize+2);
                j = table[j];
            } else {
                j++;
            }
        }
    }
}


int main(void) {
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";

    KMP(parent, pattern);    
    return 0;
}