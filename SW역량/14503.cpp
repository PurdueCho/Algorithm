#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[50][50];

// 전진
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 후진
int by[] = {1, 0, -1, 0};
int bx[] = {0, -1, 0, 1};
 
struct Robot {
	int y;
	int x;
	int d;
};

Robot robot;
queue<Robot> q;

int main() {
	scanf("%d %d", &n, &m);
    scanf("%d %d %d", &robot.y, &robot.x, &robot.d);

    for (int y = 0; y < n; ++y) {
		for (int x = 0; x < m; ++x) {
			scanf("%d", &map[y][x]);
		}
	}
	int cnt = 0;

    q.push(robot);

    while ( !q.empty() ) {
        Robot cur = q.front(); q.pop();
        
        if (map[cur.y][cur.x] == 0) {
            map[cur.y][cur.x] = 2;
            ++cnt;
        }

        for (int dir = 0; dir < 4; ++dir) { // 4방향 탐색
            // 방향 회전
            Robot next; 
            next.d = (cur.d + 3 + (dir * 3)) % 4; // 0 부터 시작 했을 때, 0 .. 3 .. 2 .. 1..
            next.y = cur.y + dy[next.d];
            next.x = cur.x + dx[next.d];
 
            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m
                || map[next.y][next.x] != 0) {
                continue;
            }
 
            q.push(next);
            break;
        }

        // 4 방향 청소 할 곳 없음
        if (q.empty()) {
            Robot next;
            next.d = cur.d;
            next.y = cur.y + by[cur.d];
            next.x = cur.x + bx[cur.d];

            if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m || map[next.y][next.x] == 1) {
                break;
            }
            q.push(next);
        }
    }

	printf("%d\n", cnt);

	return 0;
}