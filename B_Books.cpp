#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int lo = i, hi = n, sx = i-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (pref[mid + 1] - pref[i] <= t) {
                sx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        mx = max(mx, sx - i + 1);
    }

    cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
