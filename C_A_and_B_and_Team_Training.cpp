#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    if(m<n) swap(n,m);
    int tm=0;
    while(m>0 && n>0){
        if(m<n) swap(n,m);
        n-=1;
        m-=2;
        if(n>=0 && m>=0) tm++;
    }
    cout<<tm<<endl;
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
