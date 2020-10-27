#include <stdio.h>
#include <string.h>

char str[100000 + 10];
int count = 0;

int depth = 0;

int a, b;

void InputData(void)
{
    scanf("%s", str);
    while (str[count] != '\0') {
        switch (str[count])
        {
        case '(':
            a++;
            break;
        case ')':
            b++;
            break;
        default:
            break;
        }

        count++;
    }
}

int Solve() {
    int ret = 0;
    int cnt;

    //printf("'(': %d, ')': %d\n", a, b);

    if ( a < b) {
        // '(' 보다 ')' 가 더 많을때
        cnt = 0;
        for (int i = 0; i < count; i++)
        {
            switch (str[i])
            {
            case '(':
                depth++;
                break;
            case ')':
                depth--;
                cnt++;
                break;
            default:
                break;
            }

            //printf("%d. %c depth: %d\n", i, str[count], depth);

            if (depth == -1)
            {
                ret += cnt;
                break;
            }
        }
    } else if (a > b) {
        // ')' 보다 '(' 가 더 많을때
        cnt = 0;
        depth = 0;

        for (int i = count - 1; i >= 0; i--)
        {
            switch (str[i])
            {
            case ')':
                depth++;
                break;
            case '(':
                depth--;
                cnt++;
                break;
            default:
                break;
            }

            //printf("%d. %c depth: %d\n", i, str[count], depth);

            if (depth == -1)
            {
                ret += cnt;
                break;
            }
        }
    }
    
    return ret;
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