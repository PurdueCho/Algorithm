#include <iostream>
#include <queue>

using namespace std;

int main () {
    queue<int> q;
    q.push(6);
    q.push(4);
    q.push(1);
    q.pop();
    q.push(3);
    q.push(10);
    q.pop();
    q.push(11);

    while (!q.empty())
    {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}