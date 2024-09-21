#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;
    cin >> n;
    int ans = 2;
    int mx = 0;

    for (int i = 2; i <= n; i++)
    {
        int nw = n / i;
        int sum = i * nw * (nw + 1) / 2;
        if (sum > mx)
        {
            mx = sum;
            ans = i;
        }
    }

    cout << ans << endl;
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
