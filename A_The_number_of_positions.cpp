#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b,n;
    cin>>n>>a>>b;
    cout<<min(n-a,b+1)<<endl;
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
