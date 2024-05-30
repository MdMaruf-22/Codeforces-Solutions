#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    
    int cnt = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        int prb = 0;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                prb++;
                sum += vc[i];
            }
        }
        int mn = INT_MAX;
        int mx = INT_MIN;
        if(prb>1 && sum>=l && sum<=r){
            for(int i=0;i<n;i++){
                if(mask & (1 << i)){
                    mn = min(mn, vc[i]);
                    mx = max(mx, vc[i]);
                }
            }
            if(mx-mn >= x) cnt++;
        }
    }
    cout << cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
