#include <bits/stdc++.h>
using namespace std;
#define int long long
#define give_number_of_one_in_binary(x) __builtin_popcount(x)
#define count_trailing_zero_in_binary(x) __builtin_ctz(x)
#define count_leading_zero_in_binary(x) __builtin_clz(x)

const int INF = LLONG_MAX ;

struct Edge
{
    int dest,weight;
};

void Dijkstra(vector<vector<Edge>> &graph, int V, int source, vector<int> &dist)
{
    dist.assign(V, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d != dist[u])
            continue;
        for (const Edge &edge : graph[u])
        {
            int v = edge.dest;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}

void solve()
{
    int n, m, h;
    cin >> n >> m >> h;
    int V = 2 * n;
    vector<vector<Edge>> graph(V);
    for (int i = 0; i < h; i++)
    {
        int x;
        cin >> x;
        graph[x - 1].push_back({x - 1 + n, 0});
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        // Normal roads
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        // Discounted roads for layer n
        graph[u + n].push_back({v + n, w / 2});
        graph[v + n].push_back({u + n, w / 2});
    }
    for (int i = 0; i < n; i++) graph[i + n].push_back({i, 0});
    vector<int> distFrom1, distFromN;
    Dijkstra(graph, V, 0, distFrom1);
    Dijkstra(graph, V, n - 1, distFromN);
    int ans = INF;
    for (int i = 0; i < V; i++)
    {
        ans = min(ans, max(distFrom1[i], distFromN[i]));
    }

    if (ans > 1e12) cout << "-1" << endl;
    else cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
