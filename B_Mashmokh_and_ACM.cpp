#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
const int MAXN = 2010;
vector<vector<int>> divi(MAXN + 1);
const int mod = 1000000007;

//i --> size, j--> jei numebr diye seq end hobe
int dp[MAXN][MAXN];

void cntDiv() {
    for (int i = 1; i <= MAXN; ++i) {
        for (int j = i; j <= MAXN; j += i) {
            divi[j].push_back(i);
        }
    }
}

void solve()
{
    int n,k;cin>>n>>k;
    // 1,1 1,2 1,3 1,4 1,5 ..... 
    for(int j=1;j<=n;j++) dp[1][j] = 1;
    for(int i=2;i<=k;i++){
        for(int j=1;j<=n;j++){
            for(auto x:divi[j]){
                // notun size er thik 1 size kom er ta nibo, 
                // erpor new number jokhon sequence e add korbo mane must ager 
                // number ta new number er divisor hote hobe naile good seq hbe na
                dp[i][j] = (dp[i][j] + dp [i-1][x]) % mod;
            }
        }
    }
    // for(int i=1;i<=k;i++){
    //     for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
    int cnt = 0;
    for(int i=1;i<=n;i++) cnt = (cnt + dp[k][i]) % mod;
    cout<<cnt<<endl;
    
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t=1;
    //cin>>t;
    cntDiv();
    while(t--){
        solve();
    }
    return 0;
}
