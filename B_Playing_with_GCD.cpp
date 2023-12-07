#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n+1);
    for(int i=1;i<=n;i++) cin>>vc[i];
    bool dec=false;
    if(vc[1]<vc[0]) dec=true;
    if(dec==true){
        bool inc = false;
        for(int i=2;i<=n;i++){
            if(vc[i-1]<vc[i]){
                inc=true;
                break;
            }
        }
        if(inc){
            cout<<"NO"<<endl;
            return;
        }
    }
    dec=false;
    for(int i=2;i<n;i++){
        if(vc[i] % __gcd(vc[i-1],vc[i+1])){
            dec=true;
            break;
        }
    }
    if(dec) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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
