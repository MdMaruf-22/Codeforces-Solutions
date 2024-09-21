#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve()
{
    int n,k;cin>>n>>k;
    int dp[n][n];
    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++) pq.push({a[i],i});
    int sum=0;
    while(k-- && !pq.empty() ){
        int grt = pq.top().first;
        int ind = pq.top().second;
        pq.pop();  
        sum += grt;
        int nwval = max(0LL,grt - b[ind]);
        if(nwval>0LL) pq.push({nwval , ind});
    }
    cout<<sum<<endl;
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
