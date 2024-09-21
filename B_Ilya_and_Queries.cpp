#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
vector<int> dp(1e5 + 10, -1);

int calc(string& s,int l,int r){
    if(l>=r) return 0;
    if(dp[l]!=-1) return dp[l];
    int ans = (s[l]==s[l+1])?1:0;
    return dp[l] = ans + calc(s,l+1,r);
}
void solve()
{
    string s;
    cin>>s;
    int q;
    cin>>q;
    calc(s,0,s.size());
    while(q--){
        int l,r;cin>>l>>r;
        l--;r--;
        int ans = dp[l] - dp[r] ;
        cout<<ans<<endl;
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
