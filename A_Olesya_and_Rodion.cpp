#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,t;cin>>n>>t;
    if(t==10 && n==1){
        cout<<-1<<endl;
        return;
    }
    if(t==10){
        cout<<1;
        for(int i=1;i<=n-1;i++) cout<<0;
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++) cout<<t;
    cout<<endl;
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
