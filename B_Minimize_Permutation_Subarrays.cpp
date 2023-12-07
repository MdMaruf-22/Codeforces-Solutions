#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int x;cin>>x;
    int cnt1,cnt2,cntx;
    for(int i=1;i<=x;i++){
        int u;cin>>u;
        if(u==1) cnt1=i;
        if(u==2) cnt2=i;
        if(u==x) cntx=i;
    }
    if(cntx<cnt1 && cntx<cnt2) cout<<cntx<<" "<<min(cnt1,cnt2)<<endl;
    else if(cntx>cnt2 && cntx>cnt1) cout<<cntx<<" "<<max(cnt1,cnt2)<<endl;
    else cout<<x<<" "<<x<<endl;
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
