#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 1e5+10;
vector<int> dp(N,-1);
vector<int> height(N);
int k;
int calc(int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
    int cost = INT_MAX;
    for(int i=1;i<=k;i++){
        if(n-i >=0 ) cost = min(cost , calc(n-i) + abs(height[n] - height[n-i]));
    }
    return dp[n] = cost;
}


void solve()
{
    int n;cin>>n>>k;
    for(int i=0;i<n;i++) cin>>height[i];
    //cout<<calc(n-1)<<endl;
    calc(n-1);
    cout<<dp[n-1]<<endl;
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
