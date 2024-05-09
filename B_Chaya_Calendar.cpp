#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    int sum = 0;
    int mx = vc[0];
    for(int i=1;i<n;i++){
        if(vc[i]<=mx){
            int div = mx/vc[i];
            div++;
            // sum += div*vc[i];
            mx = div*vc[i];
        }
        else mx=vc[i];
    }
    cout<<mx<<endl;
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
