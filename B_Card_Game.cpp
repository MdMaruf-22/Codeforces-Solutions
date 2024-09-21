#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int ans = 0;

    int cnt1 = 0, cnt2 = 0;
    if (a1 > b1)
        cnt1++;
    else if (a1 < b1)
        cnt2++;
    if (a2 > b2)
        cnt1++;
    else if (a2 < b2)
        cnt2++;
    if (cnt1 > cnt2)
        ans++;

    cnt1 = 0, cnt2 = 0;
    if (a1 > b2)
        cnt1++;
    else if (a1 < b2)
        cnt2++;
    if (a2 > b1)
        cnt1++;
    else if (a2 < b1)
        cnt2++;
    if (cnt1 > cnt2)
        ans++;

    cnt1 = 0, cnt2 = 0;
    if (a2 > b1)
        cnt1++;
    else if (a2 < b1)
        cnt2++;
    if (a1 > b2)
        cnt1++;
    else if (a1 < b2)
        cnt2++;
    if (cnt1 > cnt2)
        ans++;

    cnt1 = 0, cnt2 = 0;
    if (a2 > b2)
        cnt1++;
    else if (a2 < b2)
        cnt2++;
    if (a1 > b1)
        cnt1++;
    else if (a1 < b1)
        cnt2++;
    if (cnt1 > cnt2)
        ans++;

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
