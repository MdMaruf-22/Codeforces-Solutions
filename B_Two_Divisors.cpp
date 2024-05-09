#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b; cin >> a >> b;
    int lcm = (a*b)/__gcd(a,b);
    if(lcm==b) lcm*=(b/a);
    cout<<lcm<<endl;
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
