#include <iostream>
#include <stack>

using namespace std;

int main () {
    stack<int> s;
    s.push(6);
    s.push(4);
    s.push(1);
    s.pop();
    s.push(3);
    s.push(10);
    s.pop();
    s.push(11);

    while ( !s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    return 0;
}