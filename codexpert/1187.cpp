#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ull unsigned long long
int score[6][3];
int games[6][3], ans;
vector<pair<int, int>> teams;

void go(int curR)
{
    // base case
    if (curR == 15)
    {
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 3; j++)
                if (score[i][j] != games[i][j])
                    return;
        ans = 1;
        return;
    }

    // solving case
    int t1 = teams[curR].first, t2 = teams[curR].second;
    games[t1][0]++, games[t2][2]++;
    go(curR + 1);
    games[t1][0]--, games[t2][2]--;
    games[t1][2]++, games[t2][0]++;
    go(curR + 1);
    games[t1][2]--, games[t2][0]--;
    games[t1][1]++, games[t2][1]++;
    go(curR + 1);
    games[t1][1]--, games[t2][1]--;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 6; i++)
    {
        for (int j = i + 1; j < 6; j++)
        {
            teams.push_back({i, j});
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                cin >> score[j][k];
                games[j][k] = 0;
            }
        }
        go(0);
        cout << ans << ' ';
        ans = 0;
    }
}
