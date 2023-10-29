#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    map<int,int> mp;
    for (int i = 1; i <= n; ++i) {
        mp[i%5]++;
    }
    int cnt=0;
    for (int x = 1; x <= m; ++x) {
        int rem = (5-x%5)%5;
        cnt+=mp[rem];
    }
    cout<<cnt<<endl;
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
