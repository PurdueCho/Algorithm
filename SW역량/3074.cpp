#include <iostream>

int t, n, m;
int tk[100001];

int main()
{

    scanf("%d", &t);
    for (int T = 0; T < t; ++T)
    {
        scanf("%d %d", &n, &m);

        long long max = 0;

        for (int N = 0; N < n; ++N)
        {
            //tk
            scanf("%d", &tk[N]);
            if (tk[N] > max)
                max = tk[N];
        }

        long long t1 = 0;
        long long t2 = max * m;
        long long mid;
        long long min = t2;

        while (t1 <= t2)
        {
            mid = (t1 + t2) / 2;
            long long ret = 0;
            for (int i = 0; i < n; ++i)
            {
                ret += (mid / tk[i]);
            }

            if (ret < m)
            {
                t1 = mid + 1;
            }
            else
            {
                if (min > mid)
                {
                    min = mid;
                }
                t2 = mid - 1;
            }
        }
        printf("#%d %lld\n", T + 1, min);
    }
    return 0;
}