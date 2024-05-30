#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if(n<3){
        cout<<*min_element(v.begin(),v.end())<<endl;
        return;
    }
    vector<vector<int>> nw;
    for (int i = 0; i < n - 2; ++i) {
        vector<int> cnt = {v[i], v[i+1], v[i+2]};
        nw.push_back(cnt);
    }

    int ans = 0;
    for (auto& cnt : nw) {
        sort(cnt.begin(), cnt.end());
        ans = max(ans, 1LL * cnt[1]);
    }

    cout << ans << endl;
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
