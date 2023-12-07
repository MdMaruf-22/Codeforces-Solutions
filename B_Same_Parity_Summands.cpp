#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    if(n<k){
        cout<<"NO"<<endl;
        return;
    }
    if(n==k){
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i++) cout<<1<<" ";
        cout<<endl;
        return;
    }
    if(n==k*2){
        cout<<"YES"<<endl;
        for(int i=1;i<=n;i+=2) cout<<2<<" ";
        cout<<endl;
        return;
    }
    if(n>2*k && n%2==0){
        cout<<"YES"<<endl;
        for(int i=1;i<k;i++) cout<<2<<" ";
        cout<<n-2*k+2<<endl;
        return;
    }
    if(n>k && k%2==n%2){
        cout<<"YES"<<endl;
        for(int i=1;i<k;i++) cout<<1<<" ";
        cout<<n-k+1<<endl;
        return;
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
