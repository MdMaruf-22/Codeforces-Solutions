#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int u;cin>>u;
        mp[u-i+1]++;
    }
    int ans=0;
    for(auto x:mp){
        ans+= (x.second*(x.second-1))/2;
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
