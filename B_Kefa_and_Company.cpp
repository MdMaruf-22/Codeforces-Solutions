#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> vc(n);

    for (int i = 0; i < n; i++) {
        cin>>vc[i].first>>vc[i].second;
    }

    sort(vc.begin(), vc.end());

    int mx = INT_MIN;
    vector<int> pref(n + 1, 0);

    for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + vc[i].second;
    for (int i = 0; i < n; i++) {
        int fck = vc[i].first;
        int lo = i, hi = n - 1, bst = i;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (vc[mid].first < fck + d) {
                bst = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        int curr = pref[bst + 1] - pref[i];
        mx = max(mx, curr);
    }

    cout << mx << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
