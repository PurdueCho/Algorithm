#include <stdio.h>

int N;
int ID[500 + 10];   // 회의번호
int S[500 + 10];    // 시작
int E[500 + 10];    // 끝
int sol[500 + 10];

struct Conference {
    int id;
    int s_time;
    int e_time;
};

struct Conference arr[500+10];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &ID[i], &S[i], &E[i]);
        arr[i].id = ID[i];
        arr[i].s_time = S[i];
        arr[i].e_time = E[i];
    }
}
void OutputData(int ans)
{
    printf("%d\n", ans);
    for (int i = 0; i < ans ; i++)
    {
        printf("%d ", sol[i]);
    }
}

void quicksort(int s, int e) {
      int L, T, P=e;
      struct Conference temp;

      if(s >= e) return;
  
      for(L=s, T=s ; L<e ; L++) {
            if(arr[L].e_time < arr[P].e_time) {
                  if(L != T) {
                        temp = arr[L];
                        arr[L] = arr[T];
                        arr[T] = temp;
                  }

                  T++;
            }
      }
      if(P != T) {
            temp = arr[P];
            arr[P] = arr[T];
            arr[T] = temp;
      }
  
      quicksort(s, T-1);
      quicksort(T+1, e);
}

void TestPrint() {
    for (int i = 0 ; i < N ; i++) {
        printf("id: %d, Start: %d End: %d time: %d\n", arr[i].id, arr[i].s_time, arr[i].e_time, arr[i].e_time - arr[i].s_time);
    }
}

int Solve() {
    int start, end, i;
    //start = 24;
    end = arr[0].e_time;
    sol[0] = arr[0].id;
    int idx = 1;

    for (i = 1 ; i < N ; i++) {
        if (arr[i].s_time >= end) {
            sol[idx++] = arr[i].id;
            end = arr[i].e_time;
        }
    }

    return idx;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    //여기서부터 작성
    quicksort(0, N-1);
    //TestPrint();
    ans = Solve();

    OutputData(ans); // 출력하는 부분
    return 0;
}