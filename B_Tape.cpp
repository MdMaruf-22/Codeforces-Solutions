#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n,m,k;cin>>n>>m>>k;
    vector<int> vc(n);
    for(int i=0;i<n;i++) cin>>vc[i];
    vector<int> preDif(n);
    preDif[0] = 0;
    for(int i=1;i<n;i++) preDif[i] = vc[i] - vc[i-1];
    sort(preDif.rbegin(), preDif.rend());
    int ans = vc[n-1] - vc[0] + 1;
    for(int i=0;i<k-1 && i<preDif.size();i++){
        ans -= (preDif[i]-1);
    } 
    cout<<ans<<endl;
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
