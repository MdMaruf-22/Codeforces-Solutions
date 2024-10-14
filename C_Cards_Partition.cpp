#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(a) a.begin(), a.end()
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)
bool chk(int mid, int sum, int k, int mx) {
    int req = (sum - 1) / mid + 1;
    return (mid * req <= sum + k) && (mid * mx <= sum + k);
}

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> vc(n);
    int sum = 0, mx = INT_MIN; 
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
        sum += vc[i];
        mx = max(mx, vc[i]);
    }

    int lo = 1, hi = n, ans = 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (chk(mid, sum, k, mx)) {
            ans = mid;  
            lo = mid + 1; 
        } else {
            hi = mid - 1; 
        }
    }
    

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        solve(); // Solve each test case
    }
    
    return 0;
}
