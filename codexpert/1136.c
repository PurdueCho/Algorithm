#include <stdio.h>

int N;
int S[10000 + 10];
int E[10000 + 10];
int present;
int absent;

int in;

//int timeline[25];

struct Data {
    int e,s;
};

struct Data data[10000+10];

// void quickSort (int s, int e) {
//     int L, T, P=e;
//     struct Data temp;

//     if (s > e) return;
    
//     for (L=s, T=s ; L < e ; L++) {
//         if (data[L].s > data[P].s)
//         {
//             if (L != T)
//             {
//                 temp = data[L];
//                 data[L] = data[T];
//                 data[T] = temp;
//             }

//             T++;
//         }
//     }

//     quickSort(s, T - 1);
//     quickSort(T+1, e);

// }

void Sorting () {
    struct Data temp;
    for (int i = 0 ; i < N - 1; i++) {
        for (int j = i ; j < N ; j++) {
            if (data[i].s > data[j].s) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &data[i].s, &data[i].e);
    }
}

void TestPrint() {
    for (int i = 0 ; i < N ; i++) {
        printf("Start: %d End: %d\n", data[i].s, data[i].e);
    }
}

void Solve() {
    int start, end;

    start = data[0].s;
    end = data[0].e;

    int abs = 0;
    int max_abs = -1;
    int pst = 0;
    int max_pst = -1;

    for (int i = 1 ; i < N; i++) {
        if (end < data[i].s ) {     // 공백이 생김

            pst = end - start; // 공백이 생기기 전까지 존재 시간

            if (max_pst < pst) {
                max_pst = pst;
            }

            abs = data[i].s - end; // 공백시간
            if (max_abs < abs)
            {
                max_abs = abs;
            }

            start = data[i].s;      // 입실시간 갱신

            if (end < data[i].e ) {
                end = data[i].e;    // 시간 연장
            }

            pst = end - start; // 마지막일 경우..
            
            if (max_pst < pst) {
                max_pst = pst;
            }
        } else if (end >= data[i].s ) { // 겹침이 생김

            if (end <= data[i].e ) {
                end = data[i].e;    // 존재 시간 연장
            }

            pst = end - start; // 존재 시간 갱신

            if (max_pst < pst)
            {
                max_pst = pst;
            }
        }
        //printf("current\n start: %d end: %d max_P: %d max_A: %d \n", start, end, max_pst, max_abs);
    }

    //printf("%d %d\n", max_pst, max_abs);
    present = max_pst;
    absent = max_abs;
}

int main(void)
{
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    //quickSort(0, N-1);
    Sorting();
    //TestPrint();
    Solve();
    

    printf("%d %d\n", present, absent); // 출력하는 부분
    return 0;
}