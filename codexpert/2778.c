#include <stdio.h>
#include <math.h>

int N; //빌딩의층수

void InputData()
{
    scanf("%d", &N);
}

int convertTo9 (int num) {
    if (num >= 5) return num - 1;
    return num;
}

int convertTo10 (int num) {
    int input = num;
    int dec;
    int ret = 0;
    int i = 0;

    while (input) {
        dec = input % 10;
        ret += dec* pow(9, i++);
        input /= 10;
    }
    //printf("%d -> %d\n", num, ret);
    return ret;
}


int Solve() {
    int input = N;
    int dig = 0;
    int nine = 0;

    int i = 0;
    while(input)
    {
        dig = input % 10;
        //printf("%d\n", dig);
        nine += (convertTo9(dig) * pow(10, i++));    // 1
        input /= 10;
    }
    //printf("%d -> %d\n", N, nine);
    int dec = convertTo10(nine);

    return dec;
}

int main()
{
    int ans = -1;
    InputData(); //입력받는부분

    //여기서부터작성
    ans = Solve();

    printf("%d\n", ans); //출력하는부분
    return 0;
}