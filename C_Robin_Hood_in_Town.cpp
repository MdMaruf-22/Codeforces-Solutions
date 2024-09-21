#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
bool chk(int x, const vector<int> &vc, int sum, int n)
{
    int avg = (sum + x + n - 1) / n;
    int unhap = (avg + 1) / 2;
    int cnt = 0;
    for (int x : vc)
    {
        if (x < unhap) cnt++;
    }
    return cnt > n / 2;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> vc[i];
        sum += vc[i];
    }
    if (n < 3)
    {
        cout << "-1"<<endl;
        return;
    }
    int lo = 0, hi = 1e15, ans = -1;
    while (lo <= hi)
    {
        int mid = lo+(hi - lo) / 2;
        if (chk(mid, vc, sum, n))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
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
