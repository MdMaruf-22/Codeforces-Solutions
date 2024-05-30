#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#define int long long
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        set<int> a_set;
        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a_set.insert(a[i]);
        }
        
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }
        
        int mxlen = 0;
        
        for (int bit = 1; bit < (1 << n); ++bit) {
            vector<int> nw;
            for (int i = 0; i < n; ++i) {
                if (bit & (1 << i)) {
                    nw.push_back(a[i]);
                }
            }
            if (nw.empty()) continue;
            int lcm_m = accumulate(nw.begin(), nw.end(), 1LL, lcm);
            if (a_set.find(lcm_m) == a_set.end()) {
                mxlen = max(mxlen, static_cast<int>(nw.size()));
            }
        }
        
        cout << mxlen << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
