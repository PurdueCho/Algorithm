#include <iostream>
#include <algorithm>

using namespace std;

char str[4];
int a = 0, b = 0, c = 0, d = 0;
int ans1 = 0;
int num, ret, i;

// int max(int a, int b)
// {
//     if (a > b)
//         return a;
//     else
//         return b;
// }

int main(int argc, char **argv)
{
    int test_case, cn;
    int T;
    
    scanf("%d", &T);

    for (test_case = 1; test_case <= T; ++test_case)
    {
        scanf("%d", &cn);
        int *e_a = new int[1000];
        int *e_b = new int[1000];

        num = 0, a = 0, b = 0, c = 0, d = 0, i = 0, ret = 0, ans1 = 0;
        for (int j = 0; j < cn; j++)
        {
            cin >> str;
            if (str[0] == '*')
            {
                if (str[1] == '*')
                { // **N, case a
                    num = str[2] - '0';
                    a = max(a, num);
                }
                else
                {
                    if (str[2] == '*')
                    { // *N*, case d
                        num = (str[1] - '0');
                        d = max(d, num);
                    }
                    else
                    { // *NN, case a
                        num = (str[1] - '0') + (str[2] - '0');
                        a = max(a, num);
                    }
                }
            }
            else
            {
                if (str[1] == '*')
                { // N*
                    if (str[2] == '*')
                    { // N**, case b
                        num = str[0] - '0';
                        b = max(b, num);
                    }
                    else
                    {                          // N*N , exception
                        e_a[i] = str[2] - '0'; // exception a
                        e_b[i] = str[0] - '0'; // exception b
                        i++;
                    }
                }
                else
                { // NN
                    if (str[2] == '*')
                    { // NN* , case b
                        num = (str[0] - '0') + (str[1] - '0');
                        b = max(b, num);
                    }
                    else
                    { // NNN, case c
                        num = (str[0] - '0') + (str[1] - '0') + (str[2] - '0');
                        c += num;
                    }
                }
            }
        }
        ans1 = a + b + c; // raw ans
        for (int n = 0; n < i; n++)
        {
            ans1 = max(ans1, e_a[n] + b + c);
            ans1 = max(ans1, a + e_b[n] + c);
        }

        for (int n = 0; n < i; n++)
        {
            for (int k = 0; k < i; k++)
            {
                if (n == k)
                    continue;
                ans1 = max(ans1, e_a[n] + e_b[k] + c);
                ans1 = max(ans1, e_a[k] + e_b[n] + c);
            }
        }
        ret = max(ans1, d);

        //cout << "#" << test_case << " " << ret << endl;
        delete[] e_a;
        delete[] e_b;
    }

    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}