#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b;cin>>a>>b;
    while(true){
        if(a==0 || b==0) break;
        if(a>=2*b) a%=(2*b);
        else if(b>=2*a) b%=(2*a);
        else break;
    }
    cout<<a<<" "<<b<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t= 1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
