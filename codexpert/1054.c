#include <stdio.h>

int N, P;
int sol;

int arr[1001] = { -1, };

int main(void)
{
    // 입력받는 부분
    scanf("%d %d", &N, &P);

    int num = N;

    // 여기서부터 작성
    int count = 0;

    // while (1) {
    //     num = num * N % P;
    //     printf("%d\n", num);

    // }
    int flag = 0;
    int j = 0;
    for (int i = 0; ; i++) {
        num = num * N %P;

        for (int idx = 0 ; idx < 1000 ; idx++) {
            if (arr[idx] == num) {
                flag = 1;
                break;
            } else {
                arr[j++] = num;
                count++;
                break;
            }
        }
        //printf("%d\n", num);
        if (flag == 1) break;
    }
    sol = count;
    // 출력하는 부분
    printf("%d", sol);

    return 0;
}