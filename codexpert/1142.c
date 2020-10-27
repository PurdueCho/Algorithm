#include <stdio.h>
#include <stdlib.h>

int N, C, M;
int S[10000 + 10];
int E[10000 + 10];
int NUM[10000 + 10];
int curLoad;
int count;

struct Table {
    int FROM, TO, BOX;
};

struct Table table[10000 + 10];

int viliage[2000+10];

void InputData(void)
{
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d %d", &table[i].FROM, &table[i].TO, &table[i].BOX);
    }
}

void Sorting() {
    struct Table temp;
    // From
    for (int i = 0 ; i < M - 1; i++) {
        for (int j = i ; j < M ; j++) {
            if (table[i].FROM < table[j].FROM) {
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }
    // TO
    for (int i = 0 ; i < M ; i++) {
        for (int j = i ; j < M ; j++) {
            if (table[i].FROM == table[j].FROM) {
                if (table[i].TO < table[j].TO) {
                    temp = table[i];
                    table[i] = table[j];
                    table[j] = temp;
                }
            }
        }
    }
}

void Test() {
    for (int i = 0 ; i < M; i++) {
        printf("%d  %d  %d\n", table[i].FROM, table[i].TO, table[i].BOX);
    }
    printf("\n");
}

void Load(int num) {
    for (int i = 0 ; i < M ; i++) { // Table
        if (table[i].FROM == num + 1) { // 해당 마을
            printf("id %d Loading... Remain: %d\n", i, C-curLoad);
            if (curLoad + table[i].BOX <= C) {     // Capa 확인
                curLoad += table[i].BOX;    //load
                printf("Load: %d\n", table[i].BOX);
            } else {
                int avail = C - curLoad;
                curLoad += avail;  // 수용가능한 만큼만 수용
                table[i].BOX = avail;
                printf("Load: %d\n", avail);
            }
            printf("Vil %d Capa.: %d Remain: %d\n", num+1, curLoad, C - curLoad);
        } else {
            continue;
        }
    }
}

void Unload(int num) {
    if (num == 0) return; // 1번 마을

    for (int i = 0 ; i < M; i++) {
        if (table[i].TO == num+1) { // 해당 마을
            curLoad -= table[i].BOX;    // 해당 마을 박스 하차
            count += table[i].BOX;
            printf("Vil %d unLoad: %d CurLoad: %d Total: %d\n", num+1, table[i].BOX, curLoad, count);
        }
    }

}

int Solve() {

    int load;
    int unload = 0;
    for (int i = 0; i < M; i++) {

        load = 0;

        for (int j = table[i].FROM; j < table[i].TO; j++) {
            load = (load < viliage[j]) ? viliage[j] : load; // 박스 최대가 될 수 있으면 값 갱신
            //printf("from: %d to: %d load: %d\n", table[i].FROM, j, load);
        }

        for (int j = table[i].FROM; j < table[i].TO; j++) {
            viliage[j] += (C-load < table[i].BOX)? C-load : table[i].BOX; // 마을로 가야될 상자 기록
            //printf("at viliage %d: %d boxes\n", j, viliage[j]);
        }
        unload += (C - load < table[i].BOX) ? C - load : table[i].BOX;
    }

    return unload;
}

void Solve2()
{
    for (int i = 0; i < N; i++)
    { // 마을 순회
        //printf("Viliage %d\n", i+1);
        Unload(i);
        Load(i);
        //Test();
    }
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Sorting();
    //Test();
    //Solve2();
    //ans = count;
    ans = Solve();
    printf("%d\n", ans); // 출력하는 부분
    return 0;
}