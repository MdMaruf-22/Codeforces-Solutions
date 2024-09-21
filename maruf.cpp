#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> h;  // Store flower heights
vector<int> dp;  // Memoization array

int calculateTime(int i, int n) {
    if (i == n - 1) {
        // Base case: The last flower takes exactly its height seconds to reach zero
        return h[i];
    }
    
    if (dp[i] != -1) {
        // If we've already calculated the time for this flower, return the memoized result
        return dp[i];
    }
    
    // Recursive case: The time for the current flower is the maximum between its height
    // and the time for the next flower + 1 second due to the wind
    dp[i] = max(h[i], calculateTime(i + 1, n) + 1);
    
    return dp[i];
}

void solve() {
    int n;
    cin >> n;
    
    h.resize(n);
    dp.assign(n, -1);  // Reset memoization array
    
    for (auto &x: h) {
        cin >> x;
    }
    cout << calculateTime(0, n) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
