#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int l,r;cin>>l>>r;
    int mid=(r-l+1)/2;
    vector<pair<int,int>> vc;
    for(int i=l;i<=r;i+=2){
        vc.push_back({i,i+1});
    }
    if(vc.size()!=mid){
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    for(auto x:vc) cout<<x.first<<" "<<x.second<<endl;
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
