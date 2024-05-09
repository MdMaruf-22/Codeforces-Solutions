#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;cin>>n>>k;
    int msb=0;
    for(int i=0;i<31;i++){
        if(k & (1<<i)){
            msb=i;
        }
    }
    int val = (1<<msb) - 1;
    if(n==1){
        cout<<k<<endl;
        return;
    }
    int nxt = k-val;
    cout<<val<<" "<<nxt<<" ";
    for(int i=0;i<n-2;i++){
        cout<<0<<" ";
    }
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
