#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    string s;
    cin >> s;
    bool ab = false, ba = false;

    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (!ab && s[i] == 'A' && s[i + 1] == 'B')
        {
            ab = true;
            i++;
        }
        else if (ab && s[i] == 'B' && s[i + 1] == 'A')
        {
            cout << "YES" << endl;
            return;
        }
    }
    ab = false;
    for (int i = 0; i < s.length() - 1; ++i)
    {
        if (!ba && s[i] == 'B' && s[i + 1] == 'A')
        {
            ba = true;
            i++;
        }
        else if (ba && s[i] == 'A' && s[i + 1] == 'B')
        {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}
