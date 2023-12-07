#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7+10;
vector<int> dp(N);
void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
        dp[vc[i]]++;
    }
    int mn=*min_element(vc.begin(),vc.end());
    int mx=*max_element(vc.begin(),vc.end());
    int cnt=dp[mn];
    for(int i=mn+1;i<=mx;i++){
        dp[i]+=cnt;
        cnt=dp[i];
    }
    int q;cin>>q;
    while(q--){
        int x;cin>>x;
        if(x>=mx) cout<<dp[mx]<<endl;
        else cout<<dp[x]<<endl;
    }
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
