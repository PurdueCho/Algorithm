/*
    에라토스테네스의 채

    소수 판별 알고리즘

    일반적인 소수 판별 알고리즘
    if (x % i == 0) return false;
    와 같은 경우 시간복잡도가 O(N)이다.

    하지만 O(N1/2) 로 계산 가능한데 왜냐하면 약수는 4 * 2 = 2 * 4 처럼 대칭을 이룬다.
    그러므로 특정한 숫자의 제곱근 까지만 약수의 여부를 검증하면 된다.

    대량의 소수를 한꺼번에 판별하고자 할떄는?
    에라토스테네스의 채를 이용..

    1. 이차원 배열을 생성하여 값을 초기화
    2. 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 모두 지운다 (자기 자신 제외).
    2-1. 이미 지워진 숫자의 경우 스킵
    3. 2부터 시작하여 남아있는 숫자를 출력

*/
#include <stdio.h>
#include <math.h>

int number = 100000;
int a[100001];

bool isPrimeNumber(int x) {
    int end = (int) sqrt (x);
    for (int i = 2 ; i <= end ; i++) { // x 의 제곱근 만큼만 약수의 여부 검증..
        if (x % 2 == 0) return false;
    }
    return true;
}

void Eratos(int x) {
    //1. 이차원 배열을 생성하여 값을 초기화
    for (int i = 2; i <= number; i++) {
        a[i] = i;
    }
    //2. 2부터 시작해서 특정 숫자의 배수에 해당하는 숫자들을 모두 지운다 (자기 자신 제외).
    for (int i = 2; i <= number; i++) {
        if(a[i] == 0) continue; // 2-1
        for (int j = i + i; j <= number ; j += i) { // 배수 마다
            a[j] = 0;
        }
    }
    // 3. 2부터 시작하여 남아있는 숫자를 출력
    for (int i = 2; i <= number; i++) {
        if(a[i] != 0) printf("%d ", a[i]);
    }
}

int main () {
    //printf("%d\n", isPrimeNumber(97));
    Eratos(number);
    return 0;
}