#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int ans = 0;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int cnt = count_leading_zero_in_binary(vc[i]);
        mp[cnt]++;
    }
    for(auto x:mp){
        ans += (x.second*(x.second-1))/2;
    }
    cout<<ans<<endl;
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
