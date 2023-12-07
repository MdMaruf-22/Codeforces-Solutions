#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    if(k>n) cout<<-1<<endl;
    else{
        int st=(n+1)/2;
        if(st%k==0) cout<<st<<endl;
        else cout<<st/k*k+k<<endl;
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
