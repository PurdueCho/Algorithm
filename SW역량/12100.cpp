/*
2048 (Easy)
시간 제한	메모리 제한	제출	정답	맞은 사람	정답 비율
1 초	512 MB	20950	5175	3031	23.129%
문제
2048 게임은 4×4 크기의 보드에서 혼자 즐기는 재미있는 게임이다. 이 링크를 누르면 게임을 해볼 수 있다.

이 게임에서 한 번의 이동은 보드 위에 있는 전체 블록을 상하좌우 네 방향 중 하나로 이동시키는 것이다. 
이때, 같은 값을 갖는 두 블록이 충돌하면 두 블록은 하나로 합쳐지게 된다.
한 번의 이동에서 이미 합쳐진 블록은 또 다른 블록과 다시 합쳐질 수 없다. 
(실제 게임에서는 이동을 한 번 할 때마다 블록이 추가되지만, 이 문제에서 블록이 추가되는 경우는 없다)

이 문제에서 다루는 2048 게임은 보드의 크기가 N×N 이다. 보드의 크기와 보드판의 블록 상태가 주어졌을 때, 최대 5번 이동해서 만들 수 있는 가장 큰 블록의 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N (1 ≤ N ≤ 20)이 주어진다. 둘째 줄부터 N개의 줄에는 게임판의 초기 상태가 주어진다. 0은 빈 칸을 나타내며, 이외의 값은 모두 블록을 나타낸다. 블록에 쓰여 있는 수는 2보다 크거나 같고, 1024보다 작거나 같은 2의 제곱꼴이다. 블록은 적어도 하나 주어진다.

출력
최대 5번 이동시켜서 얻을 수 있는 가장 큰 블록을 출력한다.

문제 설명
1회 움직임에 선택할 수 있는 경우는 4방향
최대 5번의 움직임만 생각하면 되기 때문에 다 해보면 된다.
-> 4^5 = 1024(움직임의 경우의 수)
-> 1024*20*20 = 409600(움직임의 발생 횟수 * 보드의 크기)

각 방향으로 이동시 보드의 숫자변화를 어떻게 처리할 것인가?
4방향의 4개의 함수를 구현하여 따로 처리해도 됨..
코딩의 실수와 코딩 시간을 줄이기 위해서는 한가지 방향만 구현하고,
보드를 90도 돌리는 함수를 구현하면 코딩 시간을 줄일 수 있다.

*/

#include <stdio.h>

int n, ret;

struct BOARD
{
    int map[20][20];

    void rotate()
    {
        int temp[20][20];

        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                temp[y][x] = map[n - x - 1][y];
            }
        }

        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                map[y][x] = temp[y][x];
            }
        }
    }

    int get_max()
    {
        int ret = 0;
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                if (ret < map[y][x])
                {
                    ret = map[y][x];
                }
            }
        }
        return ret;
    }

    void up()
    {
        int temp[20][20];

        for (int x = 0; x < n; ++x)
        {
            int flag = 0, target = -1;
            for (int y = 0; y < n; ++y)
            {
                if (map[y][x] == 0)
                {
                    continue;
                }
                if (flag == 1 && map[y][x] == temp[target][x])
                {
                    temp[target][x] *= 2, flag = 0;
                }
                else
                {
                    temp[++target][x] = map[y][x], flag = 1;
                }
            }
            for (++target; target < n; ++target)
            {
                temp[target][x] = 0;
            }
        }
        for (int y = 0; y < n; ++y)
        {
            for (int x = 0; x < n; ++x)
            {
                map[y][x] = temp[y][x];
            }
        }
    }
};

void dfs(BOARD cur, int count)
{
    if (count == 5)
    {
        int candi = cur.get_max();
        if (ret < candi)
        {
            ret = candi;
        }
        return;
    }

    for (int dir = 0; dir < 4; ++dir)
    {
        BOARD next = cur;
        next.up();
        dfs(next, count + 1);
        cur.rotate();
    }
}

int main()
{
    BOARD board;
    scanf("%d", &n);
    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x < n; ++x)
        {
            scanf("%d", &board.map[y][x]);
        }
    }

    ret = 0;
    dfs(board, 0);
    printf("%d\n", ret);

    return 0;
}

