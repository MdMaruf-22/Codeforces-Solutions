#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 2e5+10;
vector<int> dp(N, 0);

void preprocess() {
    for (int i = 1; i <= N; i++) {
        int sum = 0, n = i;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        dp[i] = dp[i-1] + sum;
    }
}

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    preprocess();
    while (t--) {
        solve();
    }

    return 0;
}
