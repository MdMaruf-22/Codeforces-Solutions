#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int cnt = 1;

    for (int i = 1; i < n; ++i)
    {
        bool f = true;
        for (int j = 0; j < i; ++j)
        {
            if (s[i] == s[j])
            {
                f = false;
                break;
            }
        }
        if (f)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
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
