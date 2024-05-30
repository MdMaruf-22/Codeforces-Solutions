#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<pair<int,int>,int> m12;
    map<pair<int,int>,int> m23;
    map<pair<int,int>,int> m13;
    map<vector<int>,int> sa;
    int ans = 0;
    for(int i = 0; i < n - 2; i++){
        ans += m12[{a[i], a[i + 1]}];
        m12[{a[i], a[i + 1]}]++;
        ans += m23[{a[i + 1], a[i + 2]}];
        m23[{a[i + 1], a[i + 2]}]++;
        ans += m13[{a[i], a[i + 2]}];
        m13[{a[i], a[i + 2]}]++;
        vector<int> cur;
        cur.push_back(a[i]);
        cur.push_back(a[i + 1]);
        cur.push_back(a[i + 2]);
        ans -= (3 * sa[cur]);
        sa[cur]++;
    }
    cout << ans << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
