#include <stdio.h>
 
int n, m, h, ret;
int map[31][11];
 
bool check() {
    bool ret = true;
 
    for (int i = 1; i <= n; ++i) {
        int pos = i;
 
        for (int j = 0; j <= h; ++j) {
            if (map[j][pos] == 1) {
                ++pos;
            }
            else if (map[j][pos - 1] == 1) {
                --pos;
            }
        }
 
        if (pos != i) {
            return ret = false;
        }
    }
 
    return ret;
}
 
void dfs(int count, int y, int x) {
    if (count >= ret)    return;
    if (check()) {
        ret = count;
        return;
    }
    if (count == 3) return;
    for (int i = y; i <= h; ++i) {
        for (int j = x; j < n; ++j) {
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
                map[i][j] = 1;
                dfs(count + 1, i, j);
                map[i][j] = 0;
            }
        }
        x = 1;
    }
}
 
int main()
{
    scanf("%d %d %d", &n, &m, &h);
    int a, b;
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
 
    ret = 4;
    dfs(0, 1, 1);
    if (ret == 4)   ret = -1;
    printf("%d\n", ret);
 
    return 0;
}
