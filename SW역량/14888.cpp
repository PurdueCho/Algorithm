#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int number[11];
int op[4];
int ret_min = 987654321, ret_max = -987654321;

void dfs(int ret, int index) {
    if (index == n-1)
    {
        ret_min = min(ret, ret_min);
        ret_max = max(ret, ret_max);
    
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (op[i] != 0) {
            --op[i];
            if (i == 0)
            {
                dfs(ret + number[index + 1], index + 1);
            }
            else if (i == 1)
            {
                dfs(ret - number[index + 1], index + 1);
            }
            else if (i == 2)
            {
                dfs(ret * number[index + 1], index + 1);
            }
            else if (i == 3)
            {
                dfs(ret / number[index + 1], index + 1);
            }
            ++op[i];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &number[i]);
    }
    for (int i = 0; i < 4; ++i)
    {
        scanf("%d", &op[i]);
    }

    dfs(number[0], 0);

    printf("%d\n%d\n", ret_max, ret_min);
    return 0;
}
