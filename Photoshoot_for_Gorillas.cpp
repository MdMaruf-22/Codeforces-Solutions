#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, m, k, w;
    cin >> n >> m >> k >> w;
    priority_queue<int> pq;
    for (int i = 0; i < w; i++)
    {
        int x;
        cin >> x;
        pq.push(x);
    }
    priority_queue<int> ans;
    for (int i = 0; i < n; i++){
        int fck = k;
        if (k > i+1) fck = i + 1;
        if (k - (n - i) > 0) fck -= (k - (n - i));
        for (int j = 0; j < m; j++){
            int sck = k;
            if (k > j+1) sck = j + 1;
            if (k - (m - j) > 0) sck -= (k - (m - j));
            int value = fck * sck;
            ans.push(value);
        }
    }
    int res = 0;
    for (int i = 0; i < w && !pq.empty() && !ans.empty(); i++){
        res += pq.top() * ans.top();
        pq.pop();
        ans.pop();
    }
    cout << res << endl;
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
