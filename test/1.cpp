#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int mySolution(string s)
{
    int cnt = 0;
    string open = "({[<";  // 0 1 2 3
    string close = ")}]>"; // 0 1 2 3

    vector<char> v;
    vector<char>::iterator it;

    for (auto c : s)
    {
        if (open.find(c) != -1)
        { // open
            cout << c << endl;
            v.push_back(c);
        }
        else
        { // close
            if (close.find(c) && v.empty())
            {
                return -1;
            }
        }
    }

    return cnt;
}

int main () {
    string s = "111011110011111011111100011111";
    string str2 = "1";
    cin >> s;
    s.replace(9, 5, "1");
}