#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<pair<int, int>> vc(k);
    for (int i = 0; i < k; i++) 
        cin >> vc[i].first >> vc[i].second;

    sort(vc.begin(), vc.end());
    vector<pair<int, int>> srt = vc;
    sort(srt.begin(), srt.end(), [&](const pair<int, int>& a, const pair<int, int>& b) -> bool {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });
    int lo_bro = 0, hi_bro = 0, ans_bro = 1, mx_bro = -1, curr_bro = 0;
    for (int i = 1; i <= n - d + 1; i++) {
        int j = i + d - 1;
        while (hi_bro < k && vc[hi_bro].first <= j) {
            if (vc[hi_bro].second >= i) {
                curr_bro++;
            }
            hi_bro++;
        }
        while (lo_bro < k && vc[lo_bro].second < i) {
            curr_bro--;
            lo_bro++;
        }
        if (curr_bro > mx_bro) {
            mx_bro = curr_bro;
            ans_bro = i;
        }
    }
    cout << ans_bro << " ";
    int lo_mom = 0, hi_mom = 0, ans_mom = 1, mx_mom = -1, curr_mom = 0;
    for (int i = 1; i <= n - d + 1; i++) {
        int j = i + d - 1;
        while (hi_mom < k && srt[hi_mom].first <= j) {
            if (srt[hi_mom].second >= i) {
                curr_mom++;
            }
            hi_mom++;
        }
        while (lo_mom < k && srt[lo_mom].second < i) {
            curr_mom--;
            lo_mom++;
        }
        if (mx_mom == -1 || curr_mom < mx_mom) {
            mx_mom = curr_mom;
            ans_mom = i;
        }
    }
    cout << ans_mom << endl;
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
