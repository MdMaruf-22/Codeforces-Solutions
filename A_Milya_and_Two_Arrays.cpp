#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> vc1(n), vc2(n);
    for (int i = 0; i < n; i++) cin >> vc1[i];
    for (int i = 0; i < n; i++) cin >> vc2[i];
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            s.insert(vc1[j] + vc2[i]);
        }
    }
    
    if (s.size() >= 3) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
