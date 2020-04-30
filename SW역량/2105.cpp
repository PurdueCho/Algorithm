#include <iostream>
#include <algorithm>
 
using namespace std;
 
int t, n, sx, sy, ret;
int arr[21][21];
int store[101];
 
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { 1,-1,-1,1 };
 
void dfs(int x, int y, int dir, int cnt) {
 
    if (dir > 3) return; 
 
    if (x == sx && y == sy && dir == 3) { // 시작점과 도착점이 만나고 사각형을 만났을때 (dir 3번 꺽을때)
        ret = max(ret, cnt);
    }
 
    if (store[arr[x][y]]) return;
 
    store[arr[x][y]] = 1;
 
    int nx = x + dx[dir];
    int ny = y + dy[dir];
 
    if (nx >= 0 && ny >= 0 && nx < n && ny < n)
    {
        dfs(nx, ny, dir, cnt + 1);
        dfs(nx, ny, dir + 1, cnt + 1);
    }
 
    store[arr[x][y]] = 0; // backtracking
 
    return;
}
 
int main() {
    scanf("%d", &t);
    for (int tc = 0; tc < t; ++tc) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &arr[i][j]);
            }
        }
 
        ret = -1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++) {
                // 시작 위치 기억
                sx = i; 
                sy = j;
                dfs(i, j, 0, 0);
            }
        }
 
        printf("#%d %d\n", tc+1, ret);
 
    }
 
    return 0;
}