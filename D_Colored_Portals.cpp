#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = LLONG_MAX;
const int N = 1e5+10;
vector<string> vc(N);
unordered_map<char, vector<int>> graph;
vector<vector<int>> dist;

void bfs(int src, int n) {
    queue<int> q;
    vector<int> dist_from_src(n + 1, INF);
    dist_from_src[src] = 0;
    q.push(src);
    
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for(auto ch: vc[curr]) {
            for(int child: graph[ch]) {
                if(dist_from_src[child] > dist_from_src[curr] + abs(curr - child)) {
                    dist_from_src[child] = dist_from_src[curr] + abs(curr - child);
                    q.push(child);
                }
            }
        }
    }
    for(int i = 1; i <= n; ++i) {
        dist[src][i] = dist_from_src[i];
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    graph.clear();
    dist.assign(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        cin >> vc[i];
        graph[vc[i][0]].push_back(i);
        graph[vc[i][1]].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        bfs(i, n);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (x == y) {
            cout << 0 << endl;
        } else {
            cout << (dist[x][y] == INF ? -1 : dist[x][y]) << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
