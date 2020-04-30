#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct CORE {
    int y, x;
};

int map[12][12];
vector<CORE> v;
int T,N,ret, pnum, line, ans1, ans2;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

void dfs(int index, int count, int num, int line) {
    if (count == v.size()){
        // 최대의 코어를 설치했을 때, 최소의 전선 개수
        if(num > ans1){
            ans1 = num;
            ans2 = line;
        }else if(num == ans1){
            ans1 = num;
            ans2 = min(ans2,line);
        }
        return;
    }

    // 설치
    for (int dir = 0; dir < 4 ; ++dir) {
        vector<pair<int,int>> temp;

        bool flag = false;

        int ny = v[index].y;
        int nx = v[index].x;

        // 설치 가능?
         while(1){
            if(ny == 0 || nx ==0 || ny == N-1 || nx == N-1){
                flag = true;
                break;
            }

            ny += dy[dir];
            nx += dx[dir];

            if(map[ny][nx] == 0){
                temp.push_back(make_pair(ny,nx));
            }else{
                break;
            }
        }

        if (flag) {
            // 전선 설치
            for(int j=0; j<temp.size(); j++){
                map[temp[j].first][temp[j].second] = 2;
            }

            dfs(index + 1, count+1, num + 1, line + temp.size());

            // 전선 해제
            for(int j=0; j<temp.size(); j++){
                map[temp[j].first][temp[j].second] = 0;
            }
        }
    }
    // 설치 ㄴㄴ
    dfs (index+1, count+1, num, line);

}

int main() {
    CORE core;

    scanf("%d", &T);
    for (int tc = 0 ; tc < T; ++tc) {
        ///
        v.clear();

        scanf("%d", &N);
        for (int y =0 ; y < N; ++y) {
            for (int x = 0 ; x < N; ++x) {
                scanf("%d", &map[y][x]);
                if (map[y][x] == 1) {
                    if (y == 0 || x == 0 || y == N - 1 || x == N - 1) continue;
                    core.y =y, core.x=x;
                    v.push_back(core);
                }
            }
        }

        ans1 = 0;
        ans2 = 987654321;

        dfs(0,0,0,0);
        printf("#%d %d\n", tc+1, ans2);
        ///
    }

    return 0;
}