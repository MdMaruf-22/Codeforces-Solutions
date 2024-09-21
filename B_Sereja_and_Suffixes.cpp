#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> l(m);
    for (int i = 0; i < m; i++) {
        cin >> l[i];
        l[i]--;
    }
    vector<int> distinct_count(n);
    set<int> seen;
    for (int i = n - 1; i >= 0; i--) {
        seen.insert(a[i]);
        distinct_count[i] = seen.size();
    }
    for (int i = 0; i < m; i++) {
        cout << distinct_count[l[i]] << endl;
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
