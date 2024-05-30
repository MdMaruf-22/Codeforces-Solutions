#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    for(int mask = 0 ; mask < (1<<n) ; mask++){
        int sum = 0;
        for(int i=0;i<n;i++){
            if(mask & (1<<i)) sum+=vc[i];
            else sum -= vc[i];
        }
        if(sum%360==0){
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
