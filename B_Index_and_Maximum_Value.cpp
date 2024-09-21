#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vc(n);
    
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    int mx = *max_element(vc.begin(), vc.end());
    int cnt = 0;  
    
    while (m--) {
        char op;
        int l, r;
        cin >> op >> l >> r;
        if (l <= mx + cnt && mx + cnt <= r) {
            if (op == '+') cnt++; 
            else if (op == '-') cnt--; 
        }
        
        cout << mx + cnt << " "; 
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
