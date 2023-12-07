#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x;cin>>n>>x;
    int val = 10*n-10;
    val-=n;
    val+=x;
    cout<<val+1<<endl;
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
