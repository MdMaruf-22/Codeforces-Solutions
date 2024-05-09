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
    int cnt=0;
    for(auto x:mp){
        if(x.second>2){
            int div = x.second/3;
            cnt+=div;
        }
    }
    cout<<cnt<<endl;
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
