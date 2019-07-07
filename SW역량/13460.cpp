/*
구슬 탈출 2
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
2 초	512 MB	21347	5760	3047	24.331%
문제
스타트링크에서 판매하는 어린이용 장난감 중에서 가장 인기가 많은 제품은 구슬 탈출이다. 구슬 탈출은 직사각형 보드에 빨간 구슬과 파란 구슬을 하나씩 넣은 다음, 빨간 구슬을 구멍을 통해 빼내는 게임이다.

보드의 세로 크기는 N, 가로 크기는 M이고, 편의상 1×1크기의 칸으로 나누어져 있다. 가장 바깥 행과 열은 모두 막혀져 있고, 보드에는 구멍이 하나 있다. 빨간 구슬과 파란 구슬의 크기는 보드에서 1×1크기의 칸을 가득 채우는 사이즈이고, 각각 하나씩 들어가 있다. 게임의 목표는 빨간 구슬을 구멍을 통해서 빼내는 것이다. 이때, 파란 구슬이 구멍에 들어가면 안 된다.

이때, 구슬을 손으로 건드릴 수는 없고, 중력을 이용해서 이리 저리 굴려야 한다. 왼쪽으로 기울이기, 오른쪽으로 기울이기, 위쪽으로 기울이기, 아래쪽으로 기울이기와 같은 네 가지 동작이 가능하다.

각각의 동작에서 공은 동시에 움직인다. 빨간 구슬이 구멍에 빠지면 성공이지만, 파란 구슬이 구멍에 빠지면 실패이다. 빨간 구슬과 파란 구슬이 동시에 구멍에 빠져도 실패이다. 빨간 구슬과 파란 구슬은 동시에 같은 칸에 있을 수 없다. 또, 빨간 구슬과 파란 구슬의 크기는 한 칸을 모두 차지한다. 기울이는 동작을 그만하는 것은 더 이상 구슬이 움직이지 않을 때 까지이다.

보드의 상태가 주어졌을 때, 최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 보드의 세로, 가로 크기를 의미하는 두 정수 N, M (3 ≤ N, M ≤ 10)이 주어진다. 다음 N개의 줄에 보드의 모양을 나타내는 길이 M의 문자열이 주어진다. 이 문자열은 '.', '#', 'O', 'R', 'B' 로 이루어져 있다. '.'은 빈 칸을 의미하고, '#'은 공이 이동할 수 없는 장애물 또는 벽을 의미하며, 'O'는 구멍의 위치를 의미한다. 'R'은 빨간 구슬의 위치, 'B'는 파란 구슬의 위치이다.

입력되는 모든 보드의 가장자리에는 모두 '#'이 있다. 구멍의 개수는 한 개 이며, 빨간 구슬과 파란 구슬은 항상 1개가 주어진다.

출력
최소 몇 번 만에 빨간 구슬을 구멍을 통해 빼낼 수 있는지 출력한다. 만약, 10번 이하로 움직여서 빨간 구슬을 구멍을 통해 빼낼 수 없으면 -1을 출력한다.

해설
움직이는 경우 상,하,좌,우 의 10 번이내
4^10 가지의 경우의 수 중에서 가장 빠른 것을 찾는 문제
보드가 최대 10*10 이기 때문에 한번의 기울임에 10번의 방향만 체크하면 됨으로 4^10 * 10 번 체크 필요
// 같은 방향으로 두번 움직이는 것은 의미가 없음
// 또한 이전 방향과 반대 방향으로 움직이는 것도 의미가 없음 (원위치)

큐를 이용해서 구슬의 위치를 매번 기억하고, 다음 상태로 구슬의 위치를 이동시키면 된다.
*/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct INFO {
    int ry, rx, by, bx, count;
};

INFO start;
char map[10][11]; // x 는 문자열의 끝에 종료문자를 저장하기 위함

int bfs() {
    // 전형적인 4방향 탐색
    const int dy[] = { -1, 1, 0, 0}; // 상 하 좌 우
    const int dx[] = { 0, 0, -1, 1}; // 상 하 좌 우

    int visited[10][10][10][10] = { 0,};
    queue<INFO> q;
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;

    int ret = -1;
    while (!q.empty()) {
        INFO cur = q.front();
        q.pop();
        
        if (cur.count > 10) break;
        if (map[cur.ry][cur.rx] == 'O' && map[cur.by][cur.bx] != 'O') {
            ret = cur.count;
            break;
        }

        // 4방향 탐색
        for (int dir = 0; dir < 4 ; dir++) {
            int next_ry = cur.ry;
            int next_rx = cur.rx;
            int next_by = cur.by;
            int next_bx = cur.bx;

            // 빨간공
            while (1) {
                if ( map[next_ry][next_rx] != '#' && map[next_ry][next_rx] != 'O') {
                    next_ry += dy[dir];
                    next_rx += dx[dir];
                }
                else {
                    if (map[next_ry][next_rx] == '#') {
                        next_ry -= dy[dir];
                        next_rx -= dx[dir];
                    }
                    break;
                }
            }

            // 파란공
            while (1)
            {
                if (map[next_by][next_bx] != '#' && map[next_by][next_bx] != 'O')
                {
                    next_by += dy[dir];
                    next_bx += dx[dir];
                }
                else
                {
                    if (map[next_by][next_bx] == '#')
                    {
                        next_by -= dy[dir];
                        next_bx -= dx[dir];
                    }
                    break;
                }
            }

            // 공이 겹침
            if (next_ry == next_by && next_rx == next_bx) {
                if (map[next_ry][next_rx] != 'O') {
                    int red_dist = abs(next_ry - cur.ry) + abs(next_rx - cur.rx);
                    int blue_dist = abs(next_by - cur.by) + abs(next_bx - cur.bx);
                    if (red_dist > blue_dist) {
                        next_ry -= dy[dir];
                        next_rx -= dx[dir];
                    }
                    else {
                        next_by -= dy[dir];
                        next_bx -= dx[dir];
                    }
                }
            }

            // 방문처리
            if (visited[next_ry][next_rx][next_by][next_bx] == 0) {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                INFO next;
                next.ry = next_ry;
                next.rx = next_rx;
                next.by = next_by;
                next.bx = next_bx;
                next.count = cur.count + 1;
                q.push(next);
            }
        }
    }

    return ret;
}

int main () {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0 ; i < n; i++) {
        scanf("%s", map[i]);
    }

    for (int y = 0; y<n; y++) {
        for (int x = 0; x < m; x++) {
            if (map[y][x] == 'R') { // R 위치
                start.ry = y;
                start.rx = x;
            }
            if (map[y][x] == 'B') { // B 위치
                start.by = y;
                start.bx = x;
            }
        }
    }   
    start.count = 0;

    int ret = bfs();
    printf("%d\n", ret);
}