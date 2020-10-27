#include <stdio.h>

int A[5 + 10][5 + 10];
int check[5][5] = {0,};
int B[25 + 10];

int Bingo[3][5];

int bingo = 0;

void InputData(void)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    for (int i = 0; i < 25; i++)
    {
        scanf("%d", &B[i]);
    }
}

void Check (int num) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 5; j++) {
            if (A[i][j] == num) check[i][j] = 1;
        }
    }
}

void printCheck() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 5; j++) {
            printf("%d", check[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int isBingo () {
    //printf("Bingo CHeck\n");
    int flag = 0;
    int count = 0;

    // 가로 체크
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 5; j++) {
            if (check[i][j] == 0) {
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
        if (flag == 1)
            count++;
    }

    // 세로 체크
    for (int i = 0; i < 5; i++) {
        for (int j = 0 ; j < 5; j++) {
            if (check[j][i] == 0) {
                flag = 0;
                break;
            } else {
                flag = 1;
            }
        }
        if (flag == 1)
            count++;
    }

    // 대각선 체크
    for (int i = 0; i < 5; i++) {
        if (check[i][i] == 0) {
            flag = 0;
            break;
        } else {
            flag = 1;
        }

    }
    if (flag == 1)
        count++;

    for (int i = 0; i < 5; i++) {
        if (check[i][4-i] == 0) {
            flag = 0;
            break;
        } else {
            flag = 1;
        }
    }
    if (flag == 1)
        count++;

    return count;
}

int Solve () {
    int call;
    int flag = -1;
    for (int N = 0; N < 25 ; N++) { // 사회자 콜
        call = B[N];
        Check(call);

        //printCheck();

        if (N > 4) {
            // BingoCheck
            bingo = isBingo();
        }
        if (bingo >= 3 ) return N+1;
    }

    return 0;
}

int main(void)
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}