#include<bits/stdc++.h>
using namespace std;
#define int long long
map<int,bool> mp;
void solve()
{
    int n;cin>>n;
    vector<int> vc(n+1,0);
    vector<int> dp(n+1,1);
    for(int i=1;i<=n;i++) cin>>vc[i];
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j+=i){
            if(vc[j]>vc[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
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
