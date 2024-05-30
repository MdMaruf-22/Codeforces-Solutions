#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; ++i) cin >> vc[i];
    for (int i = 0; i < n; ++i) {
        bool flag = true;
        for (int j = 0; j < n - 1; ++j) {
            if (vc[(i + j) % n] > vc[(i + j + 1) % n]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
