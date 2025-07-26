#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }

    int mx = 0;

    for (int i = 0; i < n; i++) {
        int lo = i, hi = n, sx = i-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (pref[mid + 1] - pref[i] <= t) {
                sx = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        mx = max(mx, sx - i + 1);
    }

    cout << mx << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
/*


#include <iostream>
using namespace std;

// Returns true if it is possible to form a frame of side length k 
// using at most w white and b black pins.
bool feasible(long long k, long long w, long long b) {
    // Total pins needed for a triangular frame of side length k.
    long long S = k * (k + 1) / 2;
    
    // We must have enough total pins.
    if(S > w + b) return false;
    
    // Because any sum from 0 to S is achievable with {1,...,k},
    // a valid partition exists if and only if we can choose a sum s (for white)
    // satisfying: s <= w and (S - s) <= b.
    // This is equivalent to requiring that s can be chosen in the interval [S - b, w].
    
    // If S > b then we need S - b <= w.
    if(S > b && (S - b) > w) return false;
    // Similarly, if S > w then we need S - w <= b.
    if(S > w && (S - w) > b) return false;
    
    return true;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while(t--){
        long long w, b;
        cin >> w >> b;
        
        // Set an upper bound for k. With w,b up to 10^9, w+b is at most 2e9.
        // k*(k+1)/2 <= 2e9 implies k is roughly <= 63245.
        long long lo = 0, hi = 63246;
        long long ans = 0;
        
        // Binary search for the maximum k.
        while(lo <= hi){
            long long mid = (lo + hi) / 2;
            if(feasible(mid, w, b)){
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        cout << ans << "\n";
    }
    
    return 0;
}


*/