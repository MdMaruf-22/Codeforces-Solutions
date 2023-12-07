#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    int tm = (m-1);
    int nw = ((n-tm)*(n-tm-1))/2;
    int cal ;
    if(n%m==0){
        cal=n/m;
        int ans = cal*(cal-1)/2;
        ans*=m;
        cout<<ans<<" "<<nw<<endl;
    }
    else{
        cal = n/m;
        int ans = cal*(cal-1)/2;
        ans *= (m-n%m);
        cal = (n/m)+1;
        int ano =cal*(cal-1)/2;
        ano*=(n%m);
        cout<<ans+ano<<" "<<nw<<endl;
    }
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
