#include <stdio.h>

int N; //색종이 수
int X[100 + 10];
int Y[100 + 10];

int map[100 + 10][100 + 10];

void InputData(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
        for (int x = X[i] ; x < X[i] + 10 ; x++) {
            for (int y = Y[i] ; y < Y[i] + 10; y++) {
                map[x][y] = 1;
            }
        }
    }
}

void PrintMap() {
    for (int x = 0 ; x < 100 ; x++) {
            for (int y = 0 ; y < 100; y++) {
                printf("%d", map[x][y]);
            }
            printf("\n");
        }
}

void MapSetting() {
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++) // 길이 계산
        {  
            if (map[i][j] != 0)
            {
                map[i][j] += map[i - 1][j];
            }
        }
    }
}

int Solve() {
    int i,j;
    int hor_max = 0;
    int ver_max = 0;
    int count = 0;
    int length = 0;

    int width = 1;
    int longest = 0;

    // 100 까지
    for (i = 0; i < 100; i++) {
        count = 0;
        longest = 0;
        for (j = 0; j < 100; j++) {  // 길이 계산
            // if (map[i][j] == 1) {
            //     count++;
            // } else { // 0 이 등장하면 count 저장
            //     //printf("0 등장 count: %d longest: %d\n", count, longest);
            //     longest = (longest < count) ? count:longest;
            //     count = 0;
            // } 
            if (map[i][j] != 0) {
                map[i][j] += map[i-1][j-1];
            }
        }

        longest = (longest < count) ? count : longest;

        //printf("%d 줄 가장 긴 길이: %d\n", i, longest);

        if (longest > length) { // 더 긴 경우가 나타남
            length = longest;
            width = 1;
        } 
        else if (longest == length) { // 같은 길이 나타남
            width++;
        }

        hor_max = length * width;
    }
    printf("가로 넓이: %d, 가장 긴 길이 %d 나타난 개수 %d\n", hor_max, length, width);

    // 100 까지
    length = 0;
    width = 1;

    for (i = 0; i < 100; i++) {
        count = 0;
        longest = 0;
        for (j = 0; j < 100; j++) {  // 길이 계산
            if (map[j][i] == 1) {
                count++;
            } else { // 0 이 등장하면 count 저장
                //printf("0 등장 count: %d longest: %d\n", count, longest);
                longest = (longest < count) ? count:longest;
                count = 0;
            } 
        }

        longest = (longest < count) ? count : longest;

        //printf("%d 줄 가장 긴 길이: %d\n", i, longest);

        if (longest > length) { // 더 긴 경우가 나타남
            length = longest;
            width = 1;
        } 
        else if (longest == length) { // 같은 길이 나타남
            width++;
        }

        ver_max = length * width;

    }
    printf("세로 넓이: %d, 가장 긴 길이 %d 나타난 개수 %d\n", ver_max, length, width);

    int ret = (ver_max <= hor_max)?  hor_max :  ver_max;
    return ret;
}

int Solve2() {
    int max = 0;
    int length = 0;
    int width = 1;

    for (int i = 1; i < 100; i ++) {
        for (int j = 1 ; j < 100; j++) {
            length = 999;
            width = 1;
            for (int k = j; k > 0 && map[i][k] > 0; --k) {  // width 계산
                // if (map[i][k] > 0) {
                //     if (map[i][k] < length) 
                //     {
                //         length = map[i][k]; // map이 0 되면 탈출
                //     }
                //     max = (max < length * width) ? length * width : max;
                //     //printf("%d. map(%d %d) len: %d, width: %d\n", j, i, k, length, width);
                //     width++;
                // }

                if (map[i][k] < length)
                {
                    length = map[i][k]; // map이 0 되면 탈출
                }
                max = (max < length * width) ? length * width : max;
                //printf("%d. map(%d %d) len: %d, width: %d\n", j, i, k, length, width);
                width++;
            }
        }
    }
    return max;
}

int main(void)
{
    int ans = -1;
    InputData(); //입력받는 부분

    //여기서부터 작성
    MapSetting();
    //PrintMap();
    ans = Solve2();

    printf("%d\n", ans); //출력하는 부분
    return 0;
}