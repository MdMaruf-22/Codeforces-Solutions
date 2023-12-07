#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin >> n;
    for (int i = n;; i++)
    {
        string x = to_string(i);
        bool f = true;
        for (char fck : x)
        {
            int d = fck - '0';
            if (d == 0)
                continue;
            if (i % d != 0)
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cout << i << endl;
            return;
        }
    }
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
