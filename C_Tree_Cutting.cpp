#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100001];

bool check(int x, int n, int k) {
    int components = 0;
    for (int i = 1; i <= n; i++) {
        components += (adj[i].size() + 1) / (x + 1);
    }
    return components <= k;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        
        for (int i = 1; i <= n; i++)
            adj[i].clear();
        
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int lo = 1, hi = n, ans = 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (check(mid, n, k)) {
                ans = max(ans, mid);
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        cout << ans << endl;
    }
    return 0;
}
