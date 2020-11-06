#include <iostream>
#include <queue>
using namespace std;

int n; // 보드 크기
int k; // 사과 개수
int l; // 방향 변환 횟수

int map[101][101] = {
    0,
};                               // 맵 기본값 : 0
pair<int, char> dir_change[101]; // 방향 변환
int cur_change_index = 0;

const int APPLE = 1;
const int SNAKE = -1;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //방향 전환 인덱스
    //좌회전 할 경우, cur_direction = (cur_direction + 3) % 4;
    //우회전 할 경우, cur_direction = (cur_direction + 1) % 4;
    int cur_direction = 0;

    //초기 뱀 위치
    map[0][0] = SNAKE;
    pair<int, int> head = {0, 0};
    queue<pair<int, int>> snake;
    snake.push(head);

    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y; // 사과 위치

        cin >> x >> y;
        map[x - 1][y - 1] = APPLE;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        //방향변환
        cin >> dir_change[i].first >> dir_change[i].second;
    }

    int sec = 0;

    while (1)
    {
        sec++;

        int nx = head.first + dx[cur_direction];
        int ny = head.second + dy[cur_direction];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
        {
            //벽이면 게임 끝
            break;
        }
        else if (map[nx][ny] == SNAKE)
        {
            //이동할 위치가 뱀의 몸의 일부분이면 게임 끝
            break;
        }
        else if (map[nx][ny] != APPLE)
        {
            //사과가 없으면 꼬리가 이동
            auto tail = snake.front();
            snake.pop();

            map[tail.first][tail.second] = 0;
        }

        //머리 한칸 이동
        head = {nx, ny};
        snake.push(head);

        map[nx][ny] = SNAKE;

        //진행 방향을 찾음
        int dir_change_sec = dir_change[cur_change_index].first;
        if (cur_change_index < l && dir_change_sec == sec)
        {
            char dir = dir_change[cur_change_index].second;
            if (dir == 'L')
            {
                cur_direction = (cur_direction + 3) % 4;
            }
            else if (dir == 'D')
            {
                cur_direction = (cur_direction + 1) % 4;
            }
            cur_change_index++;
        }
    }

    cout << sec << '\n';

    return 0;
}
