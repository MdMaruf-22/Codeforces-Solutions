#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;cin>>n;
    int st[n],fi[n];
    for(int i=0;i<n;i++) cin>>st[i];
    for(int i=0;i<n;i++) cin>>fi[i];
    for(int i=0;i<n-1;i++){
        if(st[i+1]<fi[i]){
            st[i+1]=fi[i];
        }
        cout<<fi[i]-st[i]<<" ";
    }
    cout<<fi[n-1]-st[n-1]<<endl;
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
