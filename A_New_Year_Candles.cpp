#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;cin>>a>>b;
    int ans=a;
    while(a>=b){
        int cnt = a/b;
        ans+=cnt;
        a = cnt + (a%b);
    }
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
