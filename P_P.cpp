#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    vector<int> vc(n);
    vector<vector<int>> tree(n + 1);  // Tree adjacency list (1-based indexing)
    
    // Read the weights of the nodes
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }
    
    // Find max and second max weights
    int mx = *max_element(vc.begin(), vc.end());
    int secMax = LLONG_MIN;  // Initialize to a very low value to ensure second max is found
    
    for (int i = 0; i < n; i++) {
        if (vc[i] != mx) {
            secMax = max(secMax, vc[i]);
        }
    }
    
    // Store all the nodes with the second maximum weight
    vector<int> secondMaxNodes;
    for (int i = 0; i < n; i++) {
        if (vc[i] == secMax) {
            secondMaxNodes.push_back(i + 1);  // Store 1-based index
        }
    }

    // Read the tree edges
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Output the nodes with the second max weight
    cout << "Second Maximum Weight: " << secMax << "\n";
    cout << "Nodes with Second Maximum Weight: ";
    for (int node : secondMaxNodes) {
        cout << node << " ";
    }
    cout << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
