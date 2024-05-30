#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x,y;cin>>x>>y;
    cout<<min(x,y);
    cout<<" ";
    cout<<max(x,y)<<endl;
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
