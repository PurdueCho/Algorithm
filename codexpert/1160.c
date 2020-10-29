#include <stdio.h>
#include <math.h>

int S, E; //출발 정류장 번호, 도착 정류장 번호

int total;

int prime[1061 + 10];

typedef struct  {
    int num;
    int time;
} Node;

Node queue[1000000];
int front, rear;
int visit[1000000];

void enQueue ( Node num ) {
    queue[rear++] = num;
}
Node deQueue () {
    return queue[front++];
}
int isEmpty() {
    if (front == rear) {
        return 1;
    }
    return 0;
}

void InputData(void)
{
    scanf("%d %d", &S, &E);
}

int isPrime( int num ) {

    if (num % 2 == 0) return 0;
    for (int i = 2 ; i < num ; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int validation (int A, int B) {
    int count = 0;
    int _a = 0, _b = 0;

    while (A)
    {
        _a = A % 10;
        A /= 10;

        _b = B % 10;
        B /= 10;
        //printf("_a _b %d %d\n", _a, _b);
        if (_a != _b) count++;
    }

    //printf("count: %d\n", count);

    if (count == 1) {
        return 1;
    } else {
        return 0;
    }
}

void Init() {
    for (int i = 1000 ; i <= 9999 ; i++) {
        if(isPrime(i)) {
            prime[total++] = i;
        }
    }
    //printf("total prime: %d sqrt: %d\n", total, (int)sqrt(total));

}

void printTest() {
    for (int i = 0 ; i < total ; i++) {
        printf("%d ", prime[i]);
    }
    printf("\n");
}

int Solve() {
    Node next;
    Node cur;
    cur.num = S;
    cur.time = 0;
    visit[S] = 1;

    enQueue(cur);   // 첫번째

    //printf("available: %d\n", validation(1033, 1733));

    while (!isEmpty()) {
        cur = deQueue();

        //printf("Cur: %d\n", cur.num);
        if (cur.num == E)   // 목적지 도착
        {
            return cur.time;
        }

        for (int i = 0 ; i < total ; i++) {
            next.num = prime[i];
            next.time = cur.time + 1;

            //printf("next: %d\n", next.num);
            if (validation(cur.num, next.num) && visit[next.num] == 0) {
                //printf("enqueue: %d\n", next.num);
                visit[next.num] = 1;
                enQueue(next);
            }
        }
    }

    return -1;

}

int main(void)
{
    int ans = -1;
    InputData(); // 입력받는 부분

    // 여기서부터 작성
    Init();
    //printTest();

    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}