#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    if (n == 1) {
        cout << 0 << endl;
        return;
    }

    multiset<int> ms; 
    ms.insert(n);
    int cnt = 0;
    while (ms.size() < n) {
        int num = *ms.rbegin(); 
        ms.erase(prev(ms.end())); 
        int mx = min(k-1,num-1);
        for (int i = 0; i < mx; i++) {
            ms.insert(1); 
        }
        ms.insert(num - k + 1); 

        cnt++;
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
