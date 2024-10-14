#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

vector<int> dp,cnt;

int calc(int i) {
    if (i == 0) return 0;    
    if (i == 1) return cnt[1]; 
    
    if (dp[i] != -1) return dp[i];
    
    int skip = calc(i - 1);                          
    int pick = calc(i - 2) + i * cnt[i];             
    
    return dp[i] = max(skip, pick);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(),a.end());
    
    cnt.assign(mx + 1, 0);
    dp.assign(mx + 1, -1);
    
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
    }
    
    cout << calc(mx) << endl;
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
