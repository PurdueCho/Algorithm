#include <stdio.h>
#include <string.h>
#include <ctype.h>

int N;
char A[20000 + 10];
int depth;

void InputData(void)
{
    scanf("%d %s", &N, A);
}

void Solve() {
    int i = 0;

    while (A[i] != '\0') {
        //printf("%c", A[i++]);


        if (A[i] == '<') {
            if (depth == N && A[i - 1] != '<' && A[i - 1] != '>')
            {
                printf(" ");
            }
            depth++;
            
        }
        else if (A[i] == '>') {
            if (depth == N && A[i - 1] != '<' && A[i - 1] != '>')
            {
                printf(" ");
            }
            depth--;
        }
        else {
            if (depth == N) {
                printf("%c", A[i]);
            }
        }
        i++;
    }   
}


int main(void)
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Solve();

    return 0;
}