#include<bits/stdc++.h>
using namespace std;
#define int long long

bool chk(int time, int m, vector<int>& t, vector<int>& z, vector<int>& y, vector<int>& res) {
    int ans = 0;
    for(int i = 0; i < t.size(); i++) {
        int proc = t[i] * z[i] + y[i];
        int cyc = time / proc;
        int rem = time % proc;
        int cnt = cyc * z[i];
        cnt += min(z[i], rem / t[i]);
        res[i] = cnt;
        ans += cnt;
    }
    return ans >= m;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> t(n), z(n), y(n);
    for(int i = 0; i < n; i++) cin >> t[i] >> z[i] >> y[i];
    int lo = 0, hi = 1e9;
    vector<int> res(n);

    while(lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if(chk(mid, m, t, z, y, res)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    chk(lo, m, t, z, y, res);

    int cnt = accumulate(res.begin(), res.end(), 0LL);
    if (cnt > m) {
        int ext = cnt - m;
        for (int i = 0; i < n; i++) {
            if (res[i] > ext) {
                res[i] -= ext;
                break;
            } else {
                ext -= res[i];
                res[i] = 0;
            }
        }
    }

    cout << lo << endl;
    for(auto x : res) cout << x << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
