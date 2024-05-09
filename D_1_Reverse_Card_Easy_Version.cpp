#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,m;cin>>n>>m;
    int ans=0;
    for(int i=2;i<=m;i++){
        ans+=((n+i)/(pow(i,2)));
    }
    cout<<ans+n<<endl;
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
