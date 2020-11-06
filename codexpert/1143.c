#include <stdio.h>
#include <stdlib.h>

int N;
int sm[100000 + 10];
int sd[100000 + 10];
int em[100000 + 10];
int ed[100000 + 10];

typedef struct {
    int start, end, duration;
} Node;

Node flowers[100000 + 10];

int compare(const void *a, const void *b)
{
    Node *ptrA = (Node *)a;
    Node *ptrB = (Node *)b;

    return (ptrA->start - ptrB->start);
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d %d", &sm[i], &sd[i], &em[i], &ed[i]);
        flowers[i].start = 100 * sm[i] + sd[i];
        flowers[i].end = 100 * em[i] + ed[i];
    }
}

int Solve() {

    int start = 301;
    int end = 301;
    int count = 1;

    for (int i = 0 ; i < N; i++) {

        if (flowers[i].start > end ) {      // 꽃이 비어있으면 종료
            break;
        }

        if (end > 1130) break;

        if (flowers[i].start <= start) {    // 다음 꽃의 피는 날짜가 현재 날짜보다 작다면 지는 날짜 비교
            if (flowers[i].end > end ) {
                end = flowers[i].end;       // 꽃을 교체하고 지는 날짜 연장
            }
        } else {
            if (flowers[i].end > end) {     // 새로운 꽃 
                start = end;                
                end = flowers[i].end;       
                count++;                    
            }
        }
        
    }

    if (end > 1130) {
        return count;
    } else {
        return 0;
    }
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    qsort(flowers, N, sizeof(Node), compare);

    // for (int i = 0; i < N ; i++) {
    //     printf("%d %d\n", flowers[i].start, flowers[i].end);
    // }

    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}

