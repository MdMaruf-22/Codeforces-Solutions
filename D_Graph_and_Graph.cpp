#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdlib>

using namespace std;

// We'll use 0-indexed vertices internally.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, s1, s2;
        cin >> n >> s1 >> s2;
        s1--;
        s2--;

        vector<vector<int>> graph1(n), graph2(n);

        int m1;
        cin >> m1;
        for (int i = 0; i < m1; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            graph1[a].push_back(b);
            graph1[b].push_back(a);
        }

        int m2;
        cin >> m2;
        for (int i = 0; i < m2; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            graph2[a].push_back(b);
            graph2[b].push_back(a);
        }

        // Sort neighbor lists to allow binary search later.
        for (int i = 0; i < n; i++) {
            sort(graph1[i].begin(), graph1[i].end());
            sort(graph2[i].begin(), graph2[i].end());
        }

        // Determine which vertices are "safe".
        vector<bool> safe(n, false);
        for (int v = 0; v < n; v++) {
            for (int j = 0; j < (int)graph1[v].size(); j++) {
                int u = graph1[v][j];
                if (binary_search(graph2[v].begin(), graph2[v].end(), u)) {
                    safe[v] = true;
                    break;
                }
            }
        }

        // We'll run Dijkstra in the product space.
        int Nstates = n * n;
        const long long INF = 1LL << 60;
        vector<long long> dist(Nstates, INF);

        int start = s1 * n + s2;
        dist[start] = 0;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push(make_pair(0, start));

        while (!pq.empty()) {
            pair<long long, int> top = pq.top();
            pq.pop();

            long long d = top.first;
            int state = top.second;

            if (d != dist[state]) {
                continue;
            }

            int i = state / n;
            int j = state % n;

            for (int p = 0; p < (int)graph1[i].size(); p++) {
                int a = graph1[i][p];
                for (int q = 0; q < (int)graph2[j].size(); q++) {
                    int b = graph2[j][q];
                    int nxt = a * n + b;
                    long long nd = d + abs(a - b);
                    if (nd < dist[nxt]) {
                        dist[nxt] = nd;
                        pq.push(make_pair(nd, nxt));
                    }
                }
            }
        }

        long long ans = INF;
        for (int v = 0; v < n; v++) {
            int state = v * n + v;
            if (safe[v] && dist[state] < ans) {
                ans = dist[state];
            }
        }

        if (ans == INF) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
