#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

vector<long long> a;
vector<vector<int>> adj;
vector<long long> subtree_sum;
vector<long long> min_kill_cost;

void dfs(int u, int parent) {
    long long total_sum = a[u];
    long long min_single_kill = LLONG_MAX;
    
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        total_sum += subtree_sum[v];
        min_single_kill = min(min_single_kill, min_kill_cost[v]);
    }

    subtree_sum[u] = total_sum;
    if (min_single_kill == LLONG_MAX) {
        min_kill_cost[u] = a[u];
    } else {
        min_kill_cost[u] = min(total_sum - a[u], min_single_kill + a[u]);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        a.resize(n + 1);
        adj.assign(n + 1, vector<int>());
        subtree_sum.assign(n + 1, 0);
        min_kill_cost.assign(n + 1, 0);
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }

        for (int i = 0; i < n - 1; ++i) {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        dfs(1, -1);

        cout << min_kill_cost[1] + sum << endl;
    }

    return 0;
}
