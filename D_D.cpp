#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int A, B;
    cin >> A >> B;

    // If A == B, we can't pick x and y such that x < y
    if (A == B) {
        cout << 0 << endl;
        return;
    }

    // Maximize gcd(x, y)
    // Candidate gcds: gcd(B, B-1), gcd(B, A)
    int max_gcd = 0;

    // Check gcd(B, B-1)
    max_gcd = max(max_gcd, __gcd(B, B - 1));

    // Check gcd(B, A)
    max_gcd = max(max_gcd, __gcd(B, A));

    cout << max_gcd << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t=1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
