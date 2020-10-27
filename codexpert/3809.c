#include <stdio.h>
#define MAXSIZE 100010
int N;                //빌딩수
int H[100000 + 10];   //빌딩높이
int sol[100000 + 10]; //각 빌딩에서 보이는 빌딩 번호

int stack[MAXSIZE];
int top = -1;

int isEmpty() {
    if (top == -1) return 1;
    else return 0;
}

int isFull() {
    if (top == MAXSIZE) return 1;
    else return 0;
}

void push(int num) {
    if (!isFull()) {
        stack[++top] = num;
    } else {
        printf("Stack is full\n");
    }
}

int pop () {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        printf("Stack is empty\n");
    }
}

int peek () {
    if (!isEmpty()) {
        //printf("peek: %d\n", stack[top]);
        return stack[top];
    } else {
        //printf("Stack is empty\n");
        return -1;
    }
}

void printStack()
{
    for (int i = 0 ; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &H[i]);
    }
}

void OutputData(void)
{
    for (int i = 1; i <= N; i++)
    {
        printf("%d\n", sol[i]);
    }
}

void Solve() {
    // Seraching
    int curH;
    int found = 0;
    

    for (int i = 1 ; i <= N ; i++) {
        //printf("Searching... H[%d]: %d\n", i, H[i]);

        if (isEmpty()) {
            push(i);
            continue;
        }

        while (!isEmpty() && H[peek()] < H[i])
        {
            sol[peek()] = i;
            pop();
        }
        push(i);
    }
    while (!isEmpty())
    {
        sol[peek()] = 0;
        pop();
    }
}


int main(void)
{
    InputData(); //입력받는 부분

    //여기서부터 작성
    //printStack();
    Solve();

    OutputData(); //출력하는 부분
    return 0;
}