#include <stdio.h>
#include <string.h>

int N;
char S[10000 + 10][20 + 10];
int check[10000 + 10];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s", S[i]);
    }
}

void Test() {
    for (int i = 0 ; i < N ; i++) {
        printf("%s\n", S[i]);
    }
    
}

void Solve() {
    int flag = 0;
    int arr[10000];
    int count = 0;

    for (int i = 1 ; i <= N-1; i++) {
        count = 0;

        for (int j = i ; j <= N; j++) {
            if (check[j] == 1) continue;
            
            int ret = strcmp (S[i], S[j]);
            //printf("%d. %d\n", i, flag);

            if (ret == 0) {
                //printf("%s == %s @ %d\n", S[i], S[j], j);
                check[j] = 1;
                arr[count++] = j;
                if (count > 1) flag = 1;
            } 
        }
        
        if (count > 1) {
            printf("%s ", S[i]);
            for (int k = 0 ; k < count ; k++) {
                printf("%d ", arr[k]);
            }
            printf("\n");
        }
    }
    //printf("%d\n", flag);
    if (flag == 0) {
        printf("unique\n");
    }
}

int main(void)
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    return 0;
}
