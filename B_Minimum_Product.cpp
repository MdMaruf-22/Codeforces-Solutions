#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
    int fck=a,sx=b,k=n;
    int mn = min(a-x,n);
    a-=mn;
    n-=mn;
    if(n){
        mn = min(b-y,n);
        b-=mn;
    }
    int prod = a*b;
    mn = min(sx-y,k);
    sx-=mn;
    k-=mn;
    // cout<<sx<<" "<<k<<endl;
    if(k){
        mn = min(fck-x,k);
        fck-=mn;
        //cout<<fck<<endl;
    }
    //cout<<"Prod: "<<prod<<endl;
    int val = fck*sx;
    //cout<<"Prod: "<<val<<endl;
    int ans = min(prod,val);
    cout<<ans<<endl;
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
