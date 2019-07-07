/*
    라빈 카프 알고리즘
    항상 빠르지는 않지만 일반적인 경우 빠르게 작동하는 간단한 구조의 문자열 매칭 알고리즘
    해시 기법을 사용
    => 긴 데이터를 그것을 상징하는 짧은 데이터로 바꾸어 주는 기법

    단순 해시 알고리즘의 경우 연산 속도가 O(1)에 달한다

    '긴글'과 '부분 문자열'의 해시 값이 일치하는 경우에만 문자열을 재검사하여 정확히 일치하는지 확인하는 알고리즘
    => 라빈 카프 알고리즘은 O(N)의 시간 복잡도를 가집니당

    긴 글 해시값 = 2 * (긴 글 해시 값 - 가장 앞에 있는 문자의 수치) + 새롭게 들어온 문자의 수치
*/

#include <iostream>

using namespace std;

void findString(string parent, string pattern) {

    int parentSize = parent.size();
    int patternSize = pattern.size();
    int parentHash = 0, patternHash = 0, power = 1;

    for (int i = 0 ; i <= parentSize - patternSize; i++) {
        if (i == 0) { // 초기화
            for (int j = 0 ; j < patternSize; j++) {
                parentHash += parent[patternSize - 1 - j] * power;
                patternHash += pattern[patternSize - 1 - j] * power;
                if ( j < patternSize - 1) power *= 2;
            }
        } else { // 해쉬 비교
            parentHash = 2 * (parentHash - parent[i-1] * power) + parent[patternSize - 1 + i];
        }
        if(parentHash == patternHash) { // 해쉬값이 일치하면 비교
            bool finded = true;
            for (int j = 0 ; j < patternSize; j++) {
                if(parent[i+j] != pattern[j]) {
                    finded = false;
                    break;
                }
            }
            if (finded) {
                printf("%d번째에서 발견했습니다.\n", i + 1);
            }
        }
    }
  
}

int main () {
    string parent = "ababacabacaabacaaba";
    string pattern = "abacaaba";
    findString(parent, pattern);
    return 0;
}