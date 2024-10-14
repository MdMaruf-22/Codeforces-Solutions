#include<bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int N = 500005;
vector<int> adj[N];
int parent[N], depth[N], dspar[N], sz[N];

void dfs(int node, int par) {
    parent[node] = par;
    for (int child : adj[node]) {
        if (child != par) {
            depth[child] = depth[node] + 1;
            dfs(child, node);
        }
    }
}

int find(int u) {
    if (dspar[u] == u) return u;
    return dspar[u] = find(dspar[u]);
}

void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sz[u] < sz[v]) swap(u, v);
        dspar[v] = u;
        sz[u] += sz[v];
    }
}

int lca(int u, int v) {
    while (u != v) {
        if (depth[u] > depth[v]) u = parent[u];
        else v = parent[v];
    }
    return u;
}

int fnd(int u, int v) {
    int l = lca(u, v);
    int ttl = depth[u] + depth[v] - 2 * depth[l];
    int mid = ttl / 2;
    if (depth[u] - depth[l] >= mid) {
        while (mid--) u = parent[u];
        return u;
    } else {
        int rem = ttl - mid;
        while (rem--) v = parent[v];
        return v;
    }
}



void solve()
{
int N;
        cin >> N;
        for (int i = 1; i <= N; i++) {
            adj[i].clear();
            depth[i] = 0;
            parent[i] = -1;
            dspar[i] = i;
            sz[i] = 1;
        }

        for (int i = 1; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, -1);

        int Q;
        cin >> Q;

        while (Q--) {
            int u, v;
            cin >> u >> v;
            cout << fnd(u, v) << '\n';
        }
}

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
