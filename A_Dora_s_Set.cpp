#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    //bijor - jor - bijor hoile gcd==1
    if (l % 2 == 0) l++;
    while (l + 2 <= r) {
        cnt++;
        l += 4; 
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
