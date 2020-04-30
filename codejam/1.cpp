#include <iostream>
#include <vector>

using namespace std;

int T, N;
int map[3][10];

int main() {

    cin >> T;

    for (int t =0 ; t < T ; t++) {
        cin >> N;

        for (int i = 0 ; i < 3 ; i++) {
            for (int k = 0 ; k < 10 ; k++) {
                map[i][k] = 0;
            }
        }
        // 2
        for (int n = 0 ; n < N ; n++) {
            string card;
            cin >> card;
            switch (card[0])
            {
            case 'R':
                map[0][(int)card[1]-'0']++;
                //r[(int)card[1]-'0']++;
                break;
            case 'B':
                map[1][(int)card[1] - '0']++;
                break;

            case 'Y':
                map[2][(int)card[1] - '0']++;
                break;
            
            default:
                break;
            }
        }

        //3
        for (int n = 0; n < N; n++)
        {
            string card;
            cin >> card;
            switch (card[0])
            {
            case 'R':
                map[0][(int)card[1] - '0']--;
                //r[(int)card[1]-'0']++;
                break;
            case 'B':
                map[1][(int)card[1] - '0']--;
                break;

            case 'Y':
                map[2][(int)card[1] - '0']--;
                break;

            default:
                break;
            }
        }

        // result
        int flag = 0;
        for (int i = 0; i < 3; i++) {
            for (int k = 0 ; k < 10; k++) {
                //cout << map[i][k];
                if (map[i][k] != 0) {
                    flag = 1;
                    break;
                }
            }
        }

        if (flag == 0) {
            cout << "NOT CHEATER" << endl;
        } else {
            cout << "CHEATER" << endl;
        }
        flag = 0;
    }
}