#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    if(n==k || n%k==0) cout<<1<<endl;
    else if(n>k) cout<<2<<endl;
    else if(k%n==0) cout<<k/n<<endl;
    else cout<<k/n+1<<endl;
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
