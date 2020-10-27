#include <stdio.h>

#define MAXSIZE 100000

int N;              //히스토그램수
int H[100000 + 10]; //히스토그램 높이

int stack[MAXSIZE + 10];
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
        ;
    }
}

int pop() {
    if (!isEmpty()) {
        return stack[top--];
    } else {
        ;
    }
}

int peak() {
    if (!isEmpty()) {
        return stack[top];
    } else {
        ;
    }
}

int InputData(void)
{
    scanf("%d", &N);
    if (N == 0)
        return 0;

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &H[i]);
    }
    return 1;
}

long long Solve() {
    long long ans = 0;
    long long left;
    long long height, width;

    for (int i = 0; i < N; i++)
    {
        left = i;
        while (!isEmpty() && H[peak()] > H[i])
        {
            height = H[peak()];
            width = i;
            pop();

            if (!isEmpty())
            {
                width = (i - peak() - 1);
            }

            if (ans < width * height)
            {
                ans = width * height;
            }
        }
        push(i);
    }

    while (!isEmpty())
    {
        height = H[peak()];
        width = N;
        pop();

        if (!isEmpty())
        {
            width = N - peak() - 1;
        }

        if (ans < width * height)
        {
            ans = width * height;
        }
    }

    return ans;
}

int main(void)
{
    long long ans = -1;
    while (InputData())
    { //입력받는 부분

        //여기서부터 작성
        ans = Solve();

        printf("%lld\n", ans); //출력하는 부분
    }
    return 0;
}