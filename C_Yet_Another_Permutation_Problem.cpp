#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{   
    int n;cin>>n;
    int even=2;
    vector<int> vc;
    vc.push_back(1);
    while(even<=n){
        vc.push_back(even);
        even*=2;
    }
    int odd = 3;
    while (odd <= n) {
    int j = odd;
    while (j <= n) {
        vc.push_back(j);
        j *= 2;
    }
    odd += 2;
}
    for(auto x:vc) cout<<x<<" ";
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
