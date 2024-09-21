#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> st(n), end(n);

    for (int i = 0; i < n; ++i) {
        cin >> st[i] >> end[i];
    }

    sort(st.begin(), st.end());
    sort(end.begin(), end.end());

    if (n == 0 || st[0] >= s) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (st[i] - end[i-1] >= s) {
            cout << "YES" << endl;
            return;
        }
    }

    if (m - end[n-1] >= s) {
        cout << "YES" << endl;
        return;
    }

    cout << "NO" << endl;
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
