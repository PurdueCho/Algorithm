#include <stdio.h>
#define MAXN (100)

int L;               //정비를 받지 않고 갈수있는 최대거리
int N;               //정비소 개수
int dist[MAXN + 10]; //정비소사이거리
int time[MAXN + 10]; //정비시간

typedef struct {
    int dist;
    int time;
}STATION;

STATION station[MAXN + 10];
int DP[MAXN + 10];
int path[MAXN + 10];
int count;

int Solve() {
    int dist;

    DP[0] = 0;
    for (int i = 1 ; i <= N+1; i++) {
        DP[i] = 999999;
        dist = 0;

        for (int j = i - 1; j >= 0 ; j--) {
            dist += station[j].dist;        // 정비소 거리
            if (dist > L) break;

            if (DP[i] > DP[j] + station[i].time) {  // 시간이 더 적은 쪽
                DP[i] = DP[j] + station[i].time;
                path[i] = j;    // 루트
                count++;
            }
        }
    }

    return DP[N + 1];
}

void path_track(int i) {

	if (i == 0) {

		if (count > 0) printf("%d\n", count);

		return;

	}
	count++;

    path_track(path[i]);
    printf("%d ", i);

}

void InputData(void)
{
    scanf("%d", &L);
    scanf("%d", &N);
    for (int i = 1; i <= N + 1; i++)
    {
        scanf("%d", &dist[i]);
        station[i].dist = dist[i];
    }
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &time[i]);
        station[i].time = time[i];
    }
}
int cnt;


int main(void)
{
    InputData(); //입력 받는 부분

    //여기서부터 작성
    int ans = Solve();

    printf("%d\n", ans);
    path_track(path[N+1]);

    return 0;
}