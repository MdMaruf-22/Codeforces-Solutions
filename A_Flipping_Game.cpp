#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int N = 3010;
int dp[N][N];

int kadane(vector<int>& vc){
    int n = vc.size();
    int curr_sum=0,max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        curr_sum = curr_sum + vc[i];
        max_sum = max(curr_sum,max_sum);
        curr_sum = max(0LL,curr_sum);
    }
    return max_sum;
}
void solve()
{
    int n;cin>>n;
    vector<int> vc(n);
    int cnt = 0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(x==0) vc[i] = 1;
        else vc[i] = -1,cnt++;
    }
    
    int ans = kadane(vc); 
    cout<<ans+cnt<<endl;
    
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
