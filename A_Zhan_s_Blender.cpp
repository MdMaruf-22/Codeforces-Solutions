#include <bits/stdc++.h>
#include <cmath> // Include cmath for ceil
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, x, y;
    cin >> n >> x >> y;

    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    
    int mn = min(x, y);
    int ans = ceil(1.00 * n / mn);
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
