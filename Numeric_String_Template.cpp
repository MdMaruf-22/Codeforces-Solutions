#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    
    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    
    int m;
    cin >> m;
    
    while (m--) {
        string s;
        cin >> s;
        
        if (s.length() != n) {
            cout << "NO\n";
            continue;
        }
        
        unordered_map<int, char> mp1;
        unordered_map<char, int> mp2;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int fck = vc[i];
            char sck = s[i];
            if (mp1.count(fck) && mp1[fck] != sck) {
                flag = false;
                break;
            }
            if (mp2.count(sck) && mp2[sck] != fck) {
                flag = false;
                break;
            }
            
            mp1[fck] = sck;
            mp2[sck] = fck;
        }
        
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
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
