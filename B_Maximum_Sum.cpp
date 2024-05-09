#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;

int kadane(vector<int>& vc) {
    int n = vc.size();
    int sum = 0;
    int val = 0;
    for (int i = 0; i < n; i++) {
        sum += vc[i];
        if (sum >= 0) val = max(sum, val);
        else sum = 0;
    }
    return val;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
        cnt += vc[i];
    }
    cnt %= MOD;
    int val = kadane(vc);
    for (int i = 0; i < k; i++) {
        cnt = (cnt + val) % MOD;
        val = (val * 2) % MOD;
    }
    if (cnt < 0) {
        cnt %= MOD;
        cnt = MOD + cnt;
    }
    cout << cnt << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
