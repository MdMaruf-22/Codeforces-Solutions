#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int query(string x)
{
    cout << "? " << x;
    cout.flush();
    int b;
    cin >> b;
    cout.flush();
    return b;
}
void solve()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        if (query('1' + s))
            s = '1' + s;
        else if (query('0' + s))
            s = '0' + s;
        else
            break;
    }
    while (s.size() != n)
    {
        if (query(s + '1'))
            s += '1';
        else
            s += '0';
    }
    cout << "! " << s << endl;
    cout.flush();
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
