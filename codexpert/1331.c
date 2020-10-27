#include <stdio.h>

char str[100000 + 10];
int count = 0;

int MAXSIZE = 100000;
int stack[100000];
int top = -1;



int isempty()
{

    if (top == -1)
        return 1;
    else
        return 0;
}

int isfull()
{

    if (top == MAXSIZE)
        return 1;
    else
        return 0;
}

int peek()
{
    return stack[top];
}

int pop()
{
    int data;

    if (!isempty())
    {
        data = stack[top];
        top = top - 1;
        //printf("pop: %d\n", data);
        return data;
    }
    else
    {
        //printf("Could not retrieve data, Stack is empty.\n");
    }
}

int push(int data)
{

    if (!isfull())
    {
        top = top + 1;
        stack[top] = data;
        //printf("push: %d\n", data);
    }
    else
    {
        //printf("Could not insert data, Stack is full.\n");
    }
}

void InputData(void)
{
    scanf("%s", str);
    while (str[count] != '\0') {
        count++;
    }
}

int isBalance () {
    int flag = 0;
    int imbalance = 0;

    for (int i = 0 ; i < count ; i++) {
        switch (str[i])
        {
        case '(':
            push(i);
            break;

        case ')':
            if (isempty() != 1) { // 스택 비어 있으면, 뒤집기 갯수 증가
                pop();
            } else {
                imbalance++;
            }
            break;
        
        default:
            break;
        }   
    }
    //printf ("data: %d, imb: %d\n", top, imbalance);

    if (isempty() && imbalance == 0) {
        return 1;
    } else {
        return -1;
    }
}

int Solve() {
    int ret = 0;
    int idx; 

    //printf("is Balance? : %d", isBalance());

    for (int i = 0; i < count ; i++) {
        switch (str[i])
        {
        case '(':
            push(i);
            break;

        case ')':
            if (!isempty()) {
                pop();
            } else {
                ret++;
                push(i);
            }
            break;
        
        default:
            break;
        }
    }
    
    //printf("바꾼거: %d, 남은거: %d\n", ret, top + 1);

    return ret + (top+1)/2;
}

int main(void)
{
    int ans = -1;

    InputData(); // 입력받는 부분

    // 여기서부터 작성
    ans = Solve();

    printf("%d\n", ans); // 출력하는 부분
    return 0;
}