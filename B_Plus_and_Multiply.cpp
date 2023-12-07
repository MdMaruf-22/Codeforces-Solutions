#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,a,b,k;
    cin>>n>>a>>b;
    
    if(a==1){
        if((n-1)%b==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return;
    }
    
    for(int i=1;i<=n;i*=a){
        if((n-i)%b==0){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
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
