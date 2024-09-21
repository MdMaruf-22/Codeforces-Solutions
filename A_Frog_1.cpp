#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 1e5+10;
vector<int> dp(N,-1);
vector<int> height(N);

int calc(int n){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n]; 
    int cost1=LLONG_MAX,cost2=LLONG_MAX;
    cost1 = calc(n-1) + abs(height[n] - height[n-1]);
    if(n>1) cost2= calc(n-2) + abs(height[n] - height[n-2]);
    return dp [n] = min(cost1,cost2);
}


void solve()
{
    int n;cin>>n;
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
