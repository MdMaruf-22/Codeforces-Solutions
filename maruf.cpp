#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(int k, const vector<pair<int, int>>& seg) {
    int ll = 0, rr = 0;
    for (const auto& e : seg) {
        ll = max(ll - k, e.first);
        rr = min(rr + k, e.second);
        if (ll > rr) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> seg(n);
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].first >> seg[i].second;
    }

    int l = -1, r = 1e9;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid, seg)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
