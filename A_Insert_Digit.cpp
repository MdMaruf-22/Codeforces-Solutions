#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s;int n,m;
    cin>>n>>m;cin>>s;
    bool f = false;
    for(auto x:s){
        int num = x-'0';
        if(m>num && !f){
            cout<<m;
            f=true;
        }
        cout<<num;
    }
    if(!f) cout<<m;
    cout<<endl;
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
