#include <stdio.h>

#define MAXSIZE 10001

int N; //직원 수
int S; //시작 직원 번호
int M;

int front = -1;
int rear = -1;
int queue[MAXSIZE];

int isEmpty() {
    if (front == rear) {
        return 1;
    } else {
        return 0;
    }
}

int isFull() {
    int temp = (rear + 1) % MAXSIZE;
    if (temp == front) return 1;
    else return 0;
}

void enQueue( int num ) {
    if(!isFull()) {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = num;
    } else {
        printf("Queue is full.\n");
    }
}

int deQueue() {
    if (!isEmpty()) {
        front = (front+1) % MAXSIZE;
        return queue[front];
    } else {
        printf("Queue is empty\n");
    }
}

void printQueue() {
    for (int i = 0; i <= rear; i++ ) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void InputData()
{
    scanf("%d %d %d", &N, &S, &M);

    for (int i = 0; i < N; i++) {
        if ((S+i)%N == 0) {
            enQueue(N);
        } else {
            enQueue((S + i) % N);
        }
        
    }
}

void Solve() {
    
    int temp;

    while (!isEmpty()) {

        for (int i = 1; i < M ; i++) { // M 번째 전까지는 뒤로
            temp = deQueue();
            enQueue(temp);
        }

        temp = deQueue(); // M 번째
        printf("%d ", temp);

    }
    printf("\n");

}

int main()
{

    InputData(); //	입력 함수

    //	코드를 작성하세요
    printQueue();
    Solve();

    return 0;
}