#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) cin >> vc[i];

    map<int, int> mp;
    for (auto x : vc) mp[x]++;

    vector<pair<int, int>> vec;
    for (auto x : mp) vec.push_back({x.second,x.first});
    sort(vec.begin(),vec.end());
    
    //for(auto x:vec) cout<<x.first<<" "<<x.second<<endl;
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        int curr = vec[i].first ;
        if (k - curr >= 0) {
            k -= curr;
            ans++;
        } else {
            break;
        }
    }
    int res = vec.size() - ans;
    if(res==0) res=1;
    cout << res << endl;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
