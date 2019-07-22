#include <iostream>
#include <vector>

using namespace std;

int C, n, m;
int ret;
vector<string> arr;
int sum;

int decode (string s) {
    if ( s == "0001101") return 0;
    if ( s == "0011001") return 1;
    if ( s == "0010011") return 2;
    if ( s == "0111101") return 3;
    if ( s == "0100011") return 4;
    if ( s == "0110001") return 5;
    if ( s == "0101111") return 6;
    if ( s == "0111011") return 7;
    if ( s == "0110111") return 8;
    if ( s == "0001011") return 9;
    return -1;
}

bool isValid ( string s ) {
    int ret = 0;
    sum = 0;
    int arr[8];
    for (int i = 0 ; i < 8 ; i++) {
        string sub = s.substr(i*7, 7);
        if (decode(sub) != -1) {
            int dec = decode(sub);
            arr[i] = dec;
            sum += dec;
        }
        else return false;
    }
    ret = (arr[0]+arr[2]+arr[4]+arr[6])*3 + (arr[1]+arr[3]+arr[5]) + arr[7];

    if (ret % 10 == 0) return true; 
    return false;
}


int main () {

    scanf("%d", &C); // # of case

    for (int i = 0 ; i < C ; i++ ) {
        arr.clear();
        scanf("%d %d", &n, &m); // 세로 , 가로
        // input
        for (int a = 0; a < n ; a++) {
            string s;
            cin >> s;
            
            int loc = s.find_last_of("1");
            if (loc != -1) {
                string str = s.substr(loc - 55, 56);
                arr.push_back(str);
            }
        }
        printf("#%d ", i+1);
        if (isValid(arr[0])) cout << sum << endl;
        else cout << 0 << endl;
    }

    // for (int a = 0; a < arr.size() ; a++ ) {
    //     cout << isValid(arr[a]) << endl;
    // }

    

    return 0;
}