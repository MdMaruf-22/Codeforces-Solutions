#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int l, r,L, R;
    cin >> l >> r>> L >> R;
    if (l > L) {
        swap(l, L);
        swap(r, R);
    }
    if (l == L) {
        if (r == R) cout << r - l << endl;
        else if (r > R)cout << R - L + 1 << endl;
        else cout << r - l + 1 << endl;
    } 
    else {
        if (r == R) cout << R - L + 1 << endl;
        else if (r > R) cout << R - L + 2 << endl;
        else {
            if (L > r) cout << 1 << endl;
            else cout << r - L + 2 << endl;
        }
    }
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
