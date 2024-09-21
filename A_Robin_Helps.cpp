#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vc(n); for (int i = 0; i < n; i++) cin >> vc[i];

    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (vc[i] >= k)
            cnt1 += vc[i];
        else if (vc[i] == 0 && cnt1 > 0){
            cnt2++;
            cnt1--;
    }
    }
    cout << cnt2 << endl;
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
