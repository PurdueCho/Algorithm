#include <stdio.h>

int y[110]; //	살균대상의 y 좌표 배열
int x[110]; //	살균대상의 x 좌표 배열
int N;      //	필터 한 변의 크기
int L;      //	LED의 범위(길이) // <= 100
int M;      //	살균대상의 개수
int sol;    //	정답

int max = -1;

int Check (int x_origin, int y_origin, int x_end, int y_end) {
    int x_mold, y_mold;
    int count = 0;

    for (int i = 0 ; i < M ; i++) {
        x_mold = x[i];
        y_mold = y[i];
        //printf("\nmold at (%d, %d)", _x, _y);

        if ((x_mold >= x_origin && x_mold <= x_end) && (y_mold >= y_origin && y_mold <= y_end))
        {
            count++; // count
            //printf(" --> kill \n");
        }
        //printf("\n");
    }
    return count;
}

void LED (int x_led, int y_led) {
    int x_origin, y_origin;
    int x_end, y_end;
    int mold;

    // origin == mold 위치 
    for (int i = 0; i < M; i++) {

        // init
        x_origin = x[i]; 
        y_origin = y[i];
        x_end = x_origin + x_led; 
        y_end = y_origin + y_led;

        // sliding
        for (int _x = 0; _x < x_led ; _x++) {
            x_origin -= _x;
            x_end -= _x;
            mold = Check(x_origin, y_origin, x_end, y_end);
            if (max < mold)
                max = mold;
        }
        
    }

}

void Solve() {

    int x_led, y_led;
    for (int x_led = 1 ; x_led < L/2 ; x_led++) {
        y_led = L/2 - x_led; // x, y 길이 (LED)
        //printf("LED: %d x %d\n", a, b);
        LED(x_led, y_led);
    }

}


int main(void)
{
    int i;

    //	입력
    scanf("%d %d %d", &N, &L, &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &y[i], &x[i]);
    }

    //	코드를 작성하세요
    Solve();
    sol = max;

    //	정답출력
    printf("%d", sol);
    return 0;
}