/*
문제
인체에 치명적인 바이러스를 연구하던 연구소에서 바이러스가 유출되었다. 다행히 바이러스는 아직 퍼지지 않았고, 바이러스의 확산을 막기 위해서 연구소에 벽을 세우려고 한다.

연구소는 크기가 N×M인 직사각형으로 나타낼 수 있으며, 직사각형은 1×1 크기의 정사각형으로 나누어져 있다. 연구소는 빈 칸, 벽으로 이루어져 있으며, 벽은 칸 하나를 가득 차지한다. 

일부 칸은 바이러스가 존재하며, 이 바이러스는 상하좌우로 인접한 빈 칸으로 모두 퍼져나갈 수 있다. 새로 세울 수 있는 벽의 개수는 3개이며, 꼭 3개를 세워야 한다.

예를 들어, 아래와 같이 연구소가 생긴 경우를 살펴보자.

2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
이때, 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 곳이다. 아무런 벽을 세우지 않는다면, 바이러스는 모든 빈 칸으로 퍼져나갈 수 있다.

2행 1열, 1행 2열, 4행 6열에 벽을 세운다면 지도의 모양은 아래와 같아지게 된다.

2 1 0 0 1 1 0
1 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 1 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
바이러스가 퍼진 뒤의 모습은 아래와 같아진다.

2 1 0 0 1 1 2
1 0 1 0 1 2 2
0 1 1 0 1 2 2
0 1 0 0 0 1 2
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
벽을 3개 세운 뒤, 바이러스가 퍼질 수 없는 곳을 안전 영역이라고 한다. 위의 지도에서 안전 영역의 크기는 27이다.

연구소의 지도가 주어졌을 때 얻을 수 있는 안전 영역 크기의 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 지도의 세로 크기 N과 가로 크기 M이 주어진다. (3 ≤ N, M ≤ 8)

둘째 줄부터 N개의 줄에 지도의 모양이 주어진다. 0은 빈 칸, 1은 벽, 2는 바이러스가 있는 위치이다. 2의 개수는 2보다 크거나 같고, 10보다 작거나 같은 자연수이다.

빈 칸의 개수는 3개 이상이다.

출력
첫째 줄에 얻을 수 있는 안전 영역의 최대 크기를 출력한다.

문제풀이
3개의 벽을 선택
최악의 경우 62C3 = 37820
bfs로 탐색하며 가스를 최대한 확장한다.
37820 경우마다 최악의 경우 62번의 반복문을 수행하게 된다.
->queue에 삽입되는 개수 만큼 반복하는데 최악의 경우 62번
->가스가 최소 2칸을 갖고 있기 때문에 미리 2개 제거 가능
37820 * 62 = 2344840
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, ret;
int map[8][8];

int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

void test_print() {
    cout << endl;
    for (int y = 0 ; y < n ; ++y) {
        for (int x = 0 ; x < m ; ++x) {
            cout << map[y][x] << " ";
        }
        cout << endl;
    }
}

void bfs() {
    queue<int> q;
    int backup[8][8];
    int visited[8][8] = { 0, };

    for (int y = 0; y< n; ++y) {
        for (int x = 0; x < m; ++x) {
            backup[y][x] = map[y][x];
            if (backup[y][x] == 2) { 
                q.push(y* 10 + x); // 바이러스의 좌표를 정수로 큐에 저장
                visited[y][x] = 1; // 방문처리
            }
        }
    }

    while ( !q.empty() ) {
        int cur = q.front(); q.pop();
        int cy = cur /10;
        int cx = cur %10;

        backup[cy][cx] = 2; // 감염

        for (int dir = 0 ; dir < 4 ; ++dir) { // 4방향 탐색
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m ) { // 범위 체크
                continue;
            }
            if (visited[ny][nx] == 0 && backup[ny][nx] == 0) { // 방문하지 않았고, 안전구역이라면 감염큐에 저장
                visited[ny][nx] = 1;
                q.push(ny * 10 + nx);
            }
        }
    }

    // 안전구역의 수
    int candi = 0;
    for (int y = 0; y < n; ++y) {
        for (int x = 0 ; x < m ; ++x) {
            if (backup[y][x] == 0) {
                candi++;
            }
        }
    }
    ret = max(ret, candi);
}


void dfs(int wall, int sy, int sx) { // count, start, start
    if (wall == 3) { // base case
        bfs();
        return;
    }

    for (int y = sy; y < n; ++y) {
        for (int x = sx; x < m; ++x) {
            if(map[y][x] == 0) {
                map[y][x] = 1;
                dfs(wall+1, y, x);
                map[y][x] = 0; // backtracking
            }
        }
        sx = 0; 
    }

}

int main () {
    scanf("%d %d", &n, &m);
    for (int y = 0; y < n ; ++y) {
        for (int x = 0; x < m ; ++x) {
            scanf("%d", &map[y][x]);
        }
    }

    ret = -1;
    dfs(0,0,0);

    printf("%d\n", ret);

    return 0;
}