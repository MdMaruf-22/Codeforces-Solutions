#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

vector<int> dp;

int calc(int i, int m, const vector<int>& a, const vector<int>& b) {
    if (i == m - 1) return a[i];
    if (dp[i] != -1) return dp[i];
    int result = calc(i + 1, m, a, b) - a[i + 1] + b[i + 1] + a[i];
    return dp[i] = result;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    int sum = 0;
    for (int i = n - 1; i >= m; i--) {
        sum += min(a[i], b[i]);
    }
    dp.assign(m, -1);
    int mn = INT_MAX;
    for (int i = m - 1 ; i >= 0; i--) {
        mn = min(calc(i, m, a, b), mn);
    }
    cout << sum + mn << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
