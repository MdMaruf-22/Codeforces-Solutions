#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
int dp[2000][3];
int calc(int i, int prev, vector<int>& vc) {
    if (i == vc.size()) return 0;  
    if (dp[i][prev] != -1) return dp[i][prev];  

    int ans = INT_MAX; 

    if (vc[i] == 0) {
        ans = min(ans, calc(i + 1, 0, vc) + 1);
    }
    if (vc[i] == 1) {
        if (prev != 1) ans = min(ans, calc(i + 1, 1, vc)); 
        ans = min(ans, calc(i + 1, 0, vc) + 1); 
    }
    if (vc[i] == 2) {
        if (prev != 2) ans = min(ans, calc(i + 1, 2, vc)); 
        ans = min(ans, calc(i + 1, 0, vc) + 1);  
    }
    if (vc[i] == 3) {
        if (prev != 1) ans = min(ans, calc(i + 1, 1, vc));  
        if (prev != 2) ans = min(ans, calc(i + 1, 2, vc));  
        ans = min(ans, calc(i + 1, 0, vc) + 1);  
    }

    return dp[i][prev] = ans;  
}

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    memset(dp, -1, sizeof(dp));
    int cnt = calc(0, 0, vc);
    cout << cnt << endl;
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
