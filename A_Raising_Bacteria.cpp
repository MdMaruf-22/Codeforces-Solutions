#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    int ans = __builtin_popcount(n);
    cout<<ans<<endl;
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
