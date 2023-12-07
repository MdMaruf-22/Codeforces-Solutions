#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{   
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int cnt = b/m;
    if(cnt<a){
        int ans = n/m * b;
        int rem = (n%m)*a;
        if(rem>b) ans+=b;
        else ans+=rem;
        cout<<ans<<endl;
        return; 
    }
    cout<<n*a<<endl;
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