#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    
    map<int, int> cnt;
    int ans=0;
    for(int i=0;i<n;++i) {
        cnt[vc[i]]++;
    }
    for(auto it:cnt) 
        if(it.second>1) ans++;
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
