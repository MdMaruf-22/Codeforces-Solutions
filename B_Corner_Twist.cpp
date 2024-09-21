#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vc1(n, vector<int>(m));
    vector<vector<int>> vc2(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            vc1[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            vc2[i][j] = c - '0';
        }
    }

    bool flag = true;
    for (int j = 0; j < m; j++)
    {
        int cola = 0, colb = 0;
        for (int i = 0; i < n; i++)
        {
            cola = (cola + vc1[i][j]) % 3;
            colb = (colb + vc2[i][j]) % 3;
        }
        if (cola != colb)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        for (int i = 0; i < n; i++)
        {
            int rowa = 0, rowb = 0;
            for (int j = 0; j < m; j++)
            {
                rowa = (rowa + vc1[i][j]) % 3;
                rowb = (rowb + vc2[i][j]) % 3;
            }
            if (rowa != rowb)
            {
                flag = false;
                break;
            }
        }
    }

    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
