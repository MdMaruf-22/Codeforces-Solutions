#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, c = 0, sum = 0;
    cin >> n;
    vector<int> vc(n);
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) cin >> vc[i]; 
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1')
        {
            if (vc[c] > vc[i]) 
            {
                swap(s[i], s[c]);
                c = i;
            }
        }
        if (s[i] == '0') c = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '1') sum += vc[i];
    }
    cout << sum << endl;
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
