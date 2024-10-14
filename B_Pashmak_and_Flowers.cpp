#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n;
    cin >> n;
    
    map<int, int> mp;
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }

     int mn = -1, mx = -1;
    for (auto x : mp) {
        if (mn == -1) mn = x.first;
        mx = x.first; 
    }
    
    int diff = mx - mn;              
    int ans = 0;
    
    if (diff == 0)  ans = (n * (n - 1)) / 2;
    else ans = mp[mn] * mp[mx];      
    
    cout << diff << " " << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t; 
    while (t--) {
        solve();
    }
    
    return 0;
}
