#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 3000;
int dp[N][N];

void solve() {
    int n, k;
    cin >> n >> k;
    dp[1][0]=0;
    for (int j = 1; j < k; j++) dp[1][j] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (j == 0) {
                for (int x = 1; x < k; x++) {
                    dp[i][j] += dp[i - 1][x];
                }
            } else {
                for (int x = 0; x < k; x++) {
                    dp[i][j] += dp[i - 1][x];
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < k; i++) ans += dp[n][i];
    
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
