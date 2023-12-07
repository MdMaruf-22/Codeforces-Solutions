#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    if(n%2==0){
        cout<<n/2<<" "<<n/2<<endl;
        return;
    }
    int div=1;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            div=i;
            break;
        }
    }
    if(div==1) cout<<1<<" "<<n-div<<endl;
    else cout<<n/div<<" "<<n-(n/div)<<endl;
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
