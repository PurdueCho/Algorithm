#include <stdio.h>

#define MAXN 110
int N, M;        //문서수, 궁금한 문서 번호
int P[100 + 10]; //문서 우선순위

typedef struct {
    int id;
    int priority;
} Print;

Print Queue[MAXN*MAXN];
int front = -1;
int rear = -1;

int IsEmpty() {
    if (front == rear) 
        return 1;
    else
        return 0;
}

// int IsFull(void)
// {
//     int tmp = (rear + 1) % MAXN; 
//     if (tmp == front)           
//         return 1;
//     else
//         return 0;
// }

void enQueue( Print num ) {

    rear = (rear + 1);
    Queue[rear] = num;

    // if (!IsFull()) {
    //     rear = (rear + 1) % MAXN;
    //     Queue[rear] = num;
    //     //printf("%d. enQueue %d\n", rear, num.priority);
    // }
}

Print deQueue( ) {
    if (IsEmpty())
        printf("Queue is Empty.\n");
    else
    {
        front = (front + 1);
        //printf("%d. deQueue %d\n", front, Queue[front].priority);
        return Queue[front];
    } 
}

void InputData(void)
{
    Print temp;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &P[i]);
        temp.id = i;
        temp.priority = P[i];
        enQueue(temp);
    }
}

int Solve() {
    Print now;
    int idx = 0;
    int isTarget = 0;
    int flag = 1;
    int ret = 1;

    while (1) {
        now = deQueue();
        //printf("Now id: %d priority: %d\n", now.id, now.priority);

        if (IsEmpty()) {
            //printf("%d 번째\n", idx+1);
            ret = idx + 1;
            break;
        }

        // 현재보다 우선순위 높은게 있으면 뒤로 보냄
        for (int i = front + 1; i <= rear ; i++) {
            //printf("Queue id: %d priority: %d\n", Queue[i].id, Queue[i].priority);
            if (now.priority < Queue[i].priority) {
                enQueue(now);
                flag = 0;
                break;
            }
        }

        // 없으면 프린트
        if (flag) {
            idx++;
            //printf("%d 개 프린트\n", idx);
            if (now.id == M) {  // 내가 궁금한거라면
                //printf("Now %d == M: %d\n", now.id, M);
                ret = idx;
                break;
            }
        }
        flag = 1;
    }

    return ret;
}

int main(void)
{
    int ans = -1;
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        InputData(); //입력받는 부분

        //여기서부터 작성
        //printf("Test: %d\n", t);
        ans = Solve();
        front = -1; rear = -1;
        Print init;
        init.id =-1;
        init.priority = 0;
        for (int i = 0 ; i < MAXN ; i++) {
            Queue[i] = init;
        }
        printf("%d\n", ans); //출력하는 부분
    }
    return 0;
}