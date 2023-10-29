#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int l,r;cin>>l>>r;
    if(r-l<2){
        cout<<-1<<endl;
        return;
    }
    if(l%2==0){
        cout<<l<<" "<<l+1<<" "<<l+2<<endl;
        return;
    }
    if(r-l==2){
        cout<<-1<<endl;
        return;
    }
    cout<<l+1<<" "<<l+2<<" "<<l+3<<endl;
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
