#include <iostream>

using namespace std;

struct data
{

    int s, e, w;

    bool operator<(const data &r) const
    {

        return e < r.e;
    }

} A[10003];

int vil[2003], n, c, m;

int main()

{

    int i, j, mx, ans = 0;

    scanf("%d %d %d", &n, &c, &m);

    for (i = 0; i < m; i++)
        scanf("%d %d %d", &A[i].s, &A[i].e, &A[i].w);

    sort(A, A + m);

    for (i = 0; i < m; i++)
    {

        mx = 0;

        for (j = A[i].s; j < A[i].e; j++)
        {

            mx = max(mx, vil[j]);
        }

        for (j = A[i].s; j < A[i].e; j++)
        {

            vil[j] += min(c - mx, A[i].w);
        }

        ans += min(c - mx, A[i].w);
    }

    printf("%d", ans);

    return 0;
}