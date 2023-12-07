#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        mp[x]++;
    }
    if(mp[1]>=1 && mp[2]>=1){
        cout<<2<<" "<<1<<" ";
        mp[2]--;
        mp[1]--;
    }
    
    for(int i=0;i<mp[2];i++) cout<<2<<" ";
    for(int i=0;i<mp[1];i++) cout<<1<<" ";
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
