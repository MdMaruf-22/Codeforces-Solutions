#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int xc, yc, k;
    cin >> xc >> yc >> k;
    vector<pair<int,int>> p;
    for(int i = 1; i <= k/2; i++) p.push_back({xc - i, yc});
    for(int i = 1; i <= k/2; i++) p.push_back({xc + i, yc});
    if (k % 2 == 1) p.push_back({xc, yc});
    for(auto x : p) cout << x.first << " " << x.second << endl;

}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
