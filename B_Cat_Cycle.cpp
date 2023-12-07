#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;cin>>n>>k;
    if(n%2==0){
        if(k<=n) cout<<k<<endl;
        else{
            if(k%n==0) cout<<n<<endl;
            else cout<<k%n<<endl;
        }
        return;
    }
    int mid = n/2;
    if(k<=mid){
        cout<<k<<endl;
        return;
    }
    
    if(k<=n){
        if(k==n) cout<<2<<endl;
        else cout<<k+1<<endl;
        return;
    }
    mid = (k-1)/mid;
    int cnt = (k%n)+(mid)%n;
    if(cnt%n==0) cout<<n<<endl;
    else cout<<cnt%n<<endl;
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
