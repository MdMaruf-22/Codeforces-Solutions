#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    for(int i=1;i<n;i++){
        int gc = __gcd(vc[i-1],vc[i]);
        if(gc!=1){
            cout<<0<<endl;
            return;
        }
    }
    int gcd1=vc[0],gcd2=vc[1];
    for(int i=0;i<n;i+=2) gcd1=__gcd(gcd1,vc[i]);
    for(int i=1;i<n;i+=2) gcd2=__gcd(gcd2,vc[i]);
    if(gcd1==gcd2) cout<<0<<endl;
    else cout<<((gcd1==1)?gcd2:gcd1)<<endl;
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
