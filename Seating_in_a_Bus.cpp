#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> vc(n);
    for(int i = 0; i < n; ++i) {
        cin >> vc[i];
    }
    
    map<int, bool> mp;
    mp[vc[0]] = true; 
    for(int i = 1; i < n; ++i) {
        int curr = vc[i];
        if(mp[curr - 1] == false && mp[curr + 1] == false) {
            cout << "NO" << endl;
            return;
        }
        mp[curr] = true; 
    }
    cout << "YES" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}
