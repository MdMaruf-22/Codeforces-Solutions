#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
vector<int> vc(N), dp(N, -1), prefix(N, 0), precal(N, -1);
int n, l, r;

int calc(int ind) {
    if (ind >= n) return 0;
    if (dp[ind] != -1) return dp[ind];
    int cnt = 0,i = precal[ind];
    if (i < n && prefix[i + 1] - prefix[ind] <= r) return dp[ind] = max(cnt, 1 + calc(i + 1));
    else return dp[ind] = max(cnt, calc(ind + 1));
}

void solve() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) cin >> vc[i];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + vc[i];
    for (int i = 0; i < n; i++) {
        int target = prefix[i] + l;
        auto it = lower_bound(prefix.begin() + i + 1, prefix.begin() + n + 1, target);
        if (it != prefix.begin() + n + 1) {
            precal[i] = distance(prefix.begin(), it) - 1;
        } else {
            precal[i] = n;
        }
    }
    
    fill(dp.begin(), dp.begin() + n, -1);

    cout << calc(0) << endl; 
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
