#include <iostream>
#define MAX 11


using namespace std;

int a[MAX][MAX];

void a_fill( int x ) {

    for (int i = 0; i < x; i ++) {
        for (int j = 0 ; j <= i ; j++) {
            if (j == 0) a[i][j] = 1;
            else if (j == i) a[i][j] = 1;
            else a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }

}

int main () {

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T ; i++ ) {
        int n;
        scanf("%d", &n);
        
        a_fill(n);

        printf("#%d\n", i +1);
        for (int i = 0 ; i < n; i++) {
            for (int j = 0 ; j < n; j++) {
                if (a[i][j] != 0) {
                    printf("%d ", a[i][j]);
                }
            }
            printf("\n");
        }
    }

    

    return 0;
}