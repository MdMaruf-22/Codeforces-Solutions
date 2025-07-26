#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int calc(int i,vector<int>& vc,vector<int>& dp){
    if(dp[i]!=-1) return dp[i];
    int mxLen = 1;
    for(int j=0;j<i;j++){
        if((vc[i]<0 && vc[j]>0) || (vc[i]>0 && vc[j]<0)){
            mxLen = max(mxLen,calc(j,vc,dp)+1);
        }
    } 
    return dp[i] = mxLen;
}



void solve()
{
    int n;
    cin>>n;
    vector<int> vc(n),dp(n,-1);
    for(int i=0;i<n;i++) cin>>vc[i];
    int ans = 1;
    for(int i=0;i<n;i++){
        //dp[i] = -1;
        ans = max(ans,calc(i,vc,dp));
    }

    cout<<ans<<endl;
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
