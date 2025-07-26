#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n;
    cin >> n;
    vector<int> v(n), vc2(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        vc2[i] = v[i];
    }
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }
    sort(vc2.begin(), vc2.end());
    vector<long long> pref2(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref2[i + 1] = pref2[i] + vc2[i];
    }

    int m;
    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << pref[r] - pref[l - 1] << endl;
        } else {
            cout << pref2[r] - pref2[l - 1] << endl;
        }
    }
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
