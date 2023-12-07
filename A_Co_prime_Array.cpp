#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    vector<int> fck;
    fck.push_back(vc[0]);
    for(int i=1;i<n;i++){
        if(__gcd(vc[i-1],vc[i])!=1){
            fck.push_back(1);
        }
        fck.push_back(vc[i]);
    }
    cout<<fck.size()-n<<endl;
    for(auto x:fck) cout<<x<<" ";
    cout<<endl;
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
