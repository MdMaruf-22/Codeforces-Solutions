#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> pref1(n+1), pref2(n+1);
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        pref1[a]++;
        pref2[b]++;
    }
    for (int i = 1; i <= n; i++) {
        pref1[i] += pref1[i-1];
        pref2[i] += pref2[i-1];
    }
    
    int most = INT_MIN, bro = 0, mom = 0, least = INT_MAX;
    for (int i = d; i <= n; i++) {
        int cur = pref1[i] - pref2[i - d];
        if (cur > most) most = cur, bro = i - d + 1;
        if (cur < least) least = cur, mom = i - d + 1;
    }
    
    cout << bro << ' ' << mom << endl;
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
