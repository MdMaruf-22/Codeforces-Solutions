#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAX_BITS = 31; 

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> cnt(n, vector<int>(MAX_BITS, 0));//O theke i porjonto jth bit set, emon element koyta

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        for (int j = 0; j < MAX_BITS; j++) {
            if (i > 0) cnt[i][j] = cnt[i - 1][j];
            if (a[i] & (1 << j)) cnt[i][j]++;
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int l, k;
        cin >> l >> k;
        l--;

        int low = l, high = n - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int curr = 0;

            for (int j = 0; j < MAX_BITS; j++) {
                int bitCnt = cnt[mid][j] - (l > 0 ? cnt[l - 1][j] : 0);//Jth bit set kina dekha
                if (bitCnt == mid - l + 1) {//Ekhon ei bit ta set tai etake include korte hobe
                    curr |= (1 << j);
                }
                //cout<<curr<<" ";
            }
            if (curr >= k) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (ans != -1) ans += 1;
        cout << ans << " ";
    }
    cout << endl;
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
