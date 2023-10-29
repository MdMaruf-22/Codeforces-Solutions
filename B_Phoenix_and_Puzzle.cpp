#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    bool f = false;
    if(n%2==0){
        n/=2;
        f=true;
        int sq = sqrt(n);
        if(sq*sq==n){
            cout<<"YES"<<endl;
            return;
        }
    }
    if(f) n*=2;
    if(n%4==0){
        n/=4;
        int sq = sqrt(n);
        if(sq*sq==n){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
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
